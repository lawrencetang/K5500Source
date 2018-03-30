#include "kmolsfit.h"
#include <math.h>
#include <QList>
//#include <QDebug>

/**
 * 宏定义，把二维的数组与一维数组的转换，取1维数组指定行、列的值
 * Buffer：1维数组
 * Row   ：行数
 * Col   ：列数
 * SizeSrc：阶数，Buffer是一个[SizeSrc + 1] * [SizeSrc]的数组，(SizeSrc + 1)为Buffer数组每行的个数
 */
#define ParaBuffer(Buffer,Row,Col) (*(Buffer + (Row) * (SizeSrc + 1) + (Col)))

/**
 * @brief PrintPara 打印系数矩阵
 *                  对于一个N阶拟合，它的系数矩阵大小是(N + 1)行(N + 2)列
 * @param Para      系数矩阵
 * @param SizeSrc   系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  成功返回：0
 */
static int PrintPara(double* Para, int SizeSrc)
{
    int i, j;
    for (i = 0; i < SizeSrc; i++)
    {
        for (j = 0; j < SizeSrc + 1; j++)
        {
            printf("%10.6lf ", ParaBuffer(Para, i, j));
        }
        printf("\r\n");
    }
    printf("\r\n");
    return 0;
}

/**
 * @brief ParalimitRow  系数矩阵的限幅处理，防止它溢出
 *                      目前这个函数很不完善，并不能很好地解决这个问题 TODO LiuJinfu
 *                      原理：矩阵解行列式，同一行乘以一个系数，行列式的解不变
 * 当然，相对溢出问题，还有一个精度问题，也是同样的思路，现在对于这两块的处理很不完善，有待优化
 * 以行为单位处理
 * @param Para          系数矩阵
 * @param SizeSrc       系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @param Row           当前待处理的行
 * @return  正常返回：0
 */
static int ParalimitRow(double* Para, int SizeSrc, int Row)
{
    int i;
    double Max, Min, Temp;

    Max = abs(ParaBuffer(Para, Row, 0));
    Min = Max;
    for (i = SizeSrc; i; i--)
    {
        Temp = abs(ParaBuffer(Para, Row, i));
        if (Max < Temp)
            Max = Temp;
        if (Min > Temp)
            Min = Temp;
    }
    // 原理：矩阵解行列式，同一行乘以一个系数，行列式的解不变
    Max = (Max + Min) * 0.000005;
    for (i = SizeSrc; i >= 0; i--)
        ParaBuffer(Para, Row, i) /= Max;
    return 0;
}

/**
 * @brief Paralimit 矩阵系数的限幅处理，调用ParalimitRow，处理所有的行
 * @param Para      系数矩阵
 * @param SizeSrc   系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  正常返回：0
 *          异常返回：-1
 */
static int Paralimit(double* Para, int SizeSrc)
{
    int i;
    for (i = 0; i < SizeSrc; i++)
        if (ParalimitRow(Para, SizeSrc, i))
            return -1;
    return 0;
}

/**
 * @brief ParaPreDealA  系数矩阵行列式变换
 * @param Para          系数矩阵
 * @param SizeSrc       系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @param Size
 * @return  正常返回：0
 */
static int ParaPreDealA(double* Para, int SizeSrc, int Size)
{
    int i, j;
    for (Size -= 1, i = 0; i < Size; i++)
    {
        for (j = 0; j < Size; j++)
        {
            ParaBuffer(Para, i, j) = ParaBuffer(Para, i, j) * ParaBuffer(Para, Size, Size) -
                                     ParaBuffer(Para, Size, j) * ParaBuffer(Para, i, Size);
        }
        ParaBuffer(Para, i, SizeSrc) = ParaBuffer(Para, i, SizeSrc) * ParaBuffer(Para, Size, Size) -
                                       ParaBuffer(Para, Size, SizeSrc) * ParaBuffer(Para, i, Size);
        ParaBuffer(Para, i, Size) = 0;
        ParalimitRow(Para, SizeSrc, i);
    }
    return 0;
}

/**
 * @brief ParaDealA 系数矩阵行列式变换，与ParaPreDealA配合
 *                  完成第一次变换，变换成三角矩阵
 * @param Para      系数矩阵
 * @param SizeSrc   系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  正常返回：0
 */
static int ParaDealA(double* Para, int SizeSrc)
{
    int i;
    for (i = SizeSrc; i; i--)
        if (ParaPreDealA(Para, SizeSrc, i))
            return -1;
    return 0;
}

/**
 * @brief ParaPreDealB  系数矩阵行列式变换
 * @param Para          系数矩阵
 * @param SizeSrc       系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @param OffSet
 * @return  正常返回：0
 */
static int ParaPreDealB(double* Para, int SizeSrc, int OffSet)
{
    int i, j;
    for (i = OffSet + 1; i < SizeSrc; i++)
    {
        for (j = OffSet + 1; j <= i; j++)
        {
            ParaBuffer(Para, i, j) *= ParaBuffer(Para, OffSet, OffSet);
        }
        ParaBuffer(Para, i, SizeSrc) = ParaBuffer(Para, i, SizeSrc) * ParaBuffer(Para, OffSet, OffSet) -
                                       ParaBuffer(Para, i, OffSet) * ParaBuffer(Para, OffSet, SizeSrc);
        ParaBuffer(Para, i, OffSet) = 0;
        ParalimitRow(Para, SizeSrc, i);
    }
    return 0;
}

/**
 * @brief ParaDealB 系数矩阵行列式变换，与ParaPreDealB配合
 *                  完成第一次变换，变换成对角矩阵，变换完毕
 * @param Para      系数矩阵
 * @param SizeSrc   系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  正常返回：0
 */
static int ParaDealB(double* Para, int SizeSrc)
{
    int i;
    for (i = 0; i < SizeSrc; i++)
    {
        if (ParaPreDealB(Para, SizeSrc, i))
            return -1;
    }
    for (i = 0; i < SizeSrc; i++)
    {
        if (ParaBuffer(Para, i, i))
        {
            ParaBuffer(Para, i, SizeSrc) /= ParaBuffer(Para, i, i);
            ParaBuffer(Para, i, i) = 1.0;
        }
    }
    return 0;
}

/**
 * @brief ParaDeal  系数矩阵变换
 * @param Para      系数矩阵
 * @param SizeSrc   系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  正常返回：0
 *          异常返回：1
 */
static int ParaDeal(double* Para, int SizeSrc)
{
    //PrintPara(Para, SizeSrc);

    Paralimit(Para, SizeSrc);

    //PrintPara(Para, SizeSrc);

    if (ParaDealA(Para, SizeSrc))
    {
        return -1;
    }

    //PrintPara(Para, SizeSrc);

    if (ParaDealB(Para, SizeSrc))
    {
        return -1;
    }

    return 0;
}

/**
 * @brief GetParaBuffer 最小二乘法的第一步就是从XY数据里面获取系数矩阵
 * @param Para          输出值：系数矩阵
 * @param X             X数据地址
 * @param Y             Y数据地址
 * @param Amount        XY数据组数
 * @param SizeSrc       系数矩阵大小，(SizeSrc)行 (SizeSrc+1)列
 * @return  正常返回：0
 */
static int GetParaBuffer(double* Para, const double* X, const double* Y, int Amount, int SizeSrc)
{
    int i, j;
    for (i = 0; i < SizeSrc; i++)
    {
        for (ParaBuffer(Para, 0, i) = 0, j = 0; j < Amount; j++)
        {
            ParaBuffer(Para, 0, i) += pow(*(X + j), 2 * (SizeSrc - 1) - i);
        }
    }
    for (i = 1; i < SizeSrc; i++)
    {
        for (ParaBuffer(Para, i, SizeSrc - 1) = 0, j = 0; j < Amount; j++)
        {
            ParaBuffer(Para, i, SizeSrc - 1) += pow(*(X + j), SizeSrc - 1 - i);
        }
    }
    for (i = 0; i < SizeSrc; i++)
    {
        for (ParaBuffer(Para, i, SizeSrc) = 0, j = 0; j < Amount; j++)
        {
            ParaBuffer(Para, i, SizeSrc) += (*(Y + j)) * pow(*(X + j), SizeSrc - 1 - i);
        }
    }
    for (i = 1; i < SizeSrc; i++)
    {
        for (j = 0; j < SizeSrc - 1; j++)
        {
            ParaBuffer(Para, i, j) = ParaBuffer(Para, i - 1, j + 1);
        }
    }
    return 0;
}

/**
 * @brief CalFit    计算拟合曲线参数
 * @param x         样本ListX
 * @param y         样本ListY
 * @param amount    样本个数
 * @param SizeSrc   拟合阶数 + 1，即拟合参数个数，SizeSrc范围[2, 6]，理论上支持无限高阶，但是更高阶需要实际验证
 * @param coefs     返回的拟合参数
 * @param r2        方差
 * @return  正确返回：0
 *          阶数非法：1
 *          数据非法：2
 */
int CalFit(QVector<double> x, QVector<double> y, int amount, int SizeSrc, QList<double> *coefs)
{
    int i;
    double *ParaK = (double *)malloc(SizeSrc * (SizeSrc + 1) * sizeof(double));
    double *BufferX = (double *)malloc(amount * sizeof(double));
    double *BufferY = (double *)malloc(amount * sizeof(double));

    // 判断阶数合理性
    if (SizeSrc < 2 || SizeSrc > 6)
    {
        return 1;
    }

    // 判断数据合理性
    if (x.size() != amount || y.size() != amount || amount < SizeSrc)
    {
        return 2;
    }

    // 类型转换
    for (i = 0; i < amount; i++)
    {
        *(BufferX + i) = x.at(i);
        *(BufferY + i) = y.at(i);
    }

    // 获取系数矩阵，给ParaK赋值
    GetParaBuffer(ParaK, BufferX, BufferY, amount, SizeSrc);

    // 系数矩阵变换
    ParaDeal(ParaK, SizeSrc);

    // 把拟合参数传出
    coefs->clear();
    for (amount = 0; amount < SizeSrc; amount++)
    {
        coefs->append(ParaBuffer(ParaK, amount, SizeSrc));
    }
    // 释放内存
    free(ParaK);
    free(BufferX);
    free(BufferY);

    return 0;
}

/**
 * @brief CalAvgVar 计算均值、方差
 *                  调用此函数前需先调用CalFit函数计算似合参数coefs，或者有现成的似合参数
 * SSE(和方差、误差平方和)：拟合数据和原始数据对应点的误差的平方和，SSE越接近于0，说明模型选择和拟合更好
 * MSE(均方差、方差)     ：预测数据和原始数据对应点误差的平方和的均值，也就是SSE/n
 * RMSE(均方根、标准差)  ：也叫回归系统的拟合标准差，是MSE的平方根
 * SSR                 ：预测数据与原始数据均值之差的平方和
 * SST                 ：原始数据和均值之差的平方和，SST = SSE + SSR
 * R-square(确定系数)   ：确定系数定义为：SSR/SST = 1 - SSE/SST
 *                      确定系数通过数据的变化来表征一个拟合的好坏，越接近1，对数据拟合越好
 * @param x         样本ListX
 * @param y         样本ListY
 * @param amount    样本个数
 * @param SizeSrc   拟合阶数 + 1，即拟合参数个数，SizeSrc范围[2, 6]，理论上支持无限高阶，但是更高阶需要实际验证
 * @param coefs     拟合参数
 * @param r2        返回值：确定系数
 * @return  正确返回：0
 *          阶数非法：1
 *          数据非法：2
 */
int CalAvgVar(QVector<double> x, QVector<double> y, int amount, int SizeSrc, QList<double> coefs, double *r2)
{
    int i;
    int j;
    QList<double> d;
    double tmp;
    double SrcAvg   = 0;    // 原始数据均值
    double DstAvg   = 0;    // 拟合数据均值
    double SSE      = 0;    // SSE(和方差、误差平方和)
    double MSE      = 0;    // MSE(均方差、方差)
    double SSR      = 0;    // 预测数据与原始数据均值之差的平方和
    double SST      = 0;    // 原始数据和均值之差的平方和
    double Rsquare  = 0;    // 确定系数

    // 判断阶数合理性
    if (SizeSrc < 2 || SizeSrc > 6)
    {
        return 1;
    }

    // 判断数据合理性
    if (x.size() != amount || y.size() != amount || coefs.size() != SizeSrc || amount < SizeSrc)
    {
        return 2;
    }

    // 计算原始数据均值
    SrcAvg = 0;
    for (i = 0; i < amount; i++)
    {
        SrcAvg += y.at(i);
    }
    SrcAvg /= amount;

    // 计算拟合数据 y = m[0] * pow(x[0], SizeSrc - 1) + m[1] * pow(x[1], SizeSrc - 2) + ... + m[amount - 1]
    // 第1个for循环用于计算y[i]，第2个for循环用于计算单个y，把每个m * pow(x)相加
    DstAvg = 0;
    for (i = 0; i < amount; i++)
    {
        tmp = 0;
        for (j = 0; j < SizeSrc; j++)
        {
            tmp += coefs.at(j) * pow(x.at(i), SizeSrc - 1 - j);
        }
        DstAvg += tmp;
        d.append(tmp);
    }

    // 计算拟合数据均值
    DstAvg /= amount;

    // 计算方差
    SSE = 0;
    MSE = 0;
    SSR = 0;
    SST = 0;
    Rsquare = 0;
    for (i = 0; i < amount; i++)
    {
        SSE += (d.at(i) - y.at(i)) * (d.at(i) - y.at(i));
        SSR += (d.at(i) - SrcAvg) * (d.at(i) - SrcAvg);
        SST += (y.at(i) - SrcAvg) * (y.at(i) - SrcAvg);
    }
    MSE = SSE / amount;
    Rsquare = 1 - SSE / SST;

    // 返回值
    *r2 = Rsquare;

    qDebug("和方差SSE = %lf，(均)方差MSE = %lf，确定系数R-square = %lf", SSE, MSE, Rsquare);

    return 0;
}
