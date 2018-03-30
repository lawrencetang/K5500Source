#include "aes.h"

static u8 AesSbox[16*16]=
{// populate the Sbox matrix
    /* 0 1 2 3 4 5 6 7 8 9 a b c d e f */
    /*0*/ 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    /*1*/ 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    /*2*/ 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    /*3*/ 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    /*4*/ 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    /*5*/ 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    /*6*/ 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    /*7*/ 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    /*8*/ 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    /*9*/ 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    /*a*/ 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    /*b*/ 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    /*c*/ 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    /*d*/ 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    /*e*/ 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    /*f*/ 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

static u8 AesiSbox[16*16]=
{
    // populate the iSbox matrix
    /* 0 1 2 3 4 5 6 7 8 9 a b c d e f */
    /*0*/ 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    /*1*/ 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    /*2*/ 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    /*3*/ 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    /*4*/ 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    /*5*/ 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    /*6*/ 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    /*7*/ 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    /*8*/ 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    /*9*/ 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    /*a*/ 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    /*b*/ 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    /*c*/ 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    /*d*/ 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    /*e*/ 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    /*f*/ 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

static u8 AesRcon[11*4]=
{
    0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00,
        0x10, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00,
        0x40, 0x00, 0x00, 0x00,
        0x80, 0x00, 0x00, 0x00,
        0x1b, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00
};


Aes::Aes() {

}

Aes::~Aes()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////
//构造函数
Aes::Aes(int keysize,u8* keyu8s) {
    SetNbNkNr(keysize);                          //设置密钥块数，轮数
    memcpy(key,keyu8s,keysize);                //字符串拷贝函数，把keyu8s的keysize个字符复制到key中
    KeyExpansion();                              //密钥扩展，必须提前做的初始化
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::SetNbNkNr(int keySize) {

    Nb=4;
    if(keySize==Bits128) {
        Nk=4; //4*4字节，128位密钥，10轮加密
        Nr=10;
    }
    else if(keySize==Bits192) {
        Nk=6; //6*4字节，192位密钥，12轮加密
        Nr=12;
    } else if(keySize==Bits256) {
        Nk=8; //8*4字节，256位密钥，14轮加密
        Nr=14;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::KeyExpansion() {

    memset(w,0,16*15);
    //拷贝seed 密钥
    for(int row=0;row<Nk;row++) {
        w[4*row+0] = key[4*row];
        w[4*row+1] = key[4*row+1];
        w[4*row+2] = key[4*row+2];
        w[4*row+3] = key[4*row+3];
    }
    u8* temp = new u8[4];
    for(int row=Nk;row<4*(Nr+1);row++) {
        temp[0]=w[4*row-4]; //当前列的前一列
        temp[1]=w[4*row-3];
        temp[2]=w[4*row-2];
        temp[3]=w[4*row-1];
        //逢nk时，对当前列的前一列作特殊处理
        if(row%Nk==0) {
            //先移位，再代换，最后和轮常量异或
            temp=SubWord(RotWord(temp));
            temp[0] = (u8)( (int)temp[0] ^ (int) AesRcon[4*(row/Nk)+0] );
            temp[1] = (u8)( (int)temp[1] ^ (int) AesRcon[4*(row/Nk)+1] );
            temp[2] = (u8)( (int)temp[2] ^ (int) AesRcon[4*(row/Nk)+2] );
            temp[3] = (u8)( (int)temp[3] ^ (int) AesRcon[4*(row/Nk)+3] );
        }else if ( Nk > 6 && (row % Nk == 4) ) {
            //这个还没有搞清楚
            temp = SubWord(temp);
        }

        // w[row] = w[row-Nk] xor temp
        w[4*row+0] = (u8) ( (int) w[4*(row-Nk)+0] ^ (int)temp[0] );
        w[4*row+1] = (u8) ( (int) w[4*(row-Nk)+1] ^ (int)temp[1] );
        w[4*row+2] = (u8) ( (int) w[4*(row-Nk)+2] ^ (int)temp[2] );
        w[4*row+3] = (u8) ( (int) w[4*(row-Nk)+3] ^ (int)temp[3] );
    } // for loop

}
////////////////////////////////////////////////////////////////////////////////////////////////
//密钥移位函数
u8* Aes::RotWord(u8* word) {

    u8* temp = new u8[4];
    temp[0] = word[1];
    temp[1] = word[2];
    temp[2] = word[3];
    temp[3] = word[0];
    return temp;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//密钥字代换函数
u8* Aes::SubWord(u8* word) {

    u8* temp = new u8[4];
    for(int j=0;j<4;j++) {
        //实际上也可以写成AesSbox[[j]];因为两者相等
        temp[j] = AesSbox[16*(word[j] >> 4)+(word[j] & 0x0f)];
    }
    return temp;

}
////////////////////////////////////////////////////////////////////////////////////////////////
//Aes加密函数
void Aes::Cipher(u8* input, u8* output) {

    memset(&State[0][0],0,16);
    //这里是先写列后写行的，即输入是一列一列的进来的
    for(int i=0;i<4*Nb;i++) {
        State[i%4][i/4]=input[i];                    //换成先写行后写列也是可以的，只要在输出时也是这样就可以了
    }
    AddRoundKey(0);                                    //轮密钥加

    // main round loop
    for (int round = 1; round <= (Nr - 1); round++) {
        Subu8s();                                    //字节代换
        ShiftRows();                                   //行移位
        MixColumns();                                  //列混淆
        AddRoundKey(round);                            //轮密钥加
    }

    Subu8s();                                        //字节代换
    ShiftRows();                                       //行移位
    AddRoundKey(Nr);                                   //轮密钥加

    // output = state
    for (int i = 0; i < (4 * Nb); i++) {
        output[i] = State[i % 4][ i / 4];
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////
//Aes解密函数
void Aes::InvCipher(u8* input,u8* output) {

    memset(&State[0][0],0,16);
    for (int i = 0; i < (4 * Nb); i++) {
        State[i % 4][ i / 4] = input[i];
    }

    AddRoundKey(Nr);

    // main round loop
    for (int round = Nr-1; round >= 1; round--) {
        InvShiftRows();
        InvSubu8s();
        AddRoundKey(round);
        InvMixColumns();
    } // end main round loop for InvCipher

    InvShiftRows();
    InvSubu8s();
    AddRoundKey(0);

    // output = state
    for (int i = 0; i < (4 * Nb); i++) {
        output[i] = State[i % 4][ i / 4];
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
//轮密钥加
void Aes::AddRoundKey(int round) {

    int i,j; //i行 j列 //因为密钥w是一列一列排列的，即 k0 k4 k8 k12
    // k1 k5 k9 k13
    // k2 k6 k10k14
    // k3 k7 k11k15
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            // 所以i行j列的下标是4*((round*4)+j)+i即16*round+4*j+i
            State[i][j]=(u8)((int)State[i][j]^(int)w[4*((round*4)+j)+i]);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
//字节代换函数
void Aes::Subu8s() {

    //Page 103
    int i,j;
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            State[i][j]=AesSbox[State[i][j]];
            //因为 16*(State[i][j]>>4)+State[i][j]&0x0f=State[i][j]
        }
    }
}

void Aes::InvSubu8s() {

    int i,j;
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            State[i][j]=AesiSbox[State[i][j]]; //因为 16*(State[i][j]>>4)+State[i][j]&0x0f=State[i][j]
        }
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::ShiftRows() {

    u8 temp[4*4]; //Page105
    int i,j;
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            temp[4*i+j]=State[i][j];
        }
    }
    for(i=1;i<4;i++) {
        for(j=0;j<4;j++) {
            if(i==1)State[i][j]=temp[4*i+(j+1)%4];                    //第一行左移1位
            else if(i==2)State[i][j]=temp[4*i+(j+2)%4];                //第二行左移2位
            else if(i==3)State[i][j]=temp[4*i+(j+3)%4];                //第三行左移3位
        }
    }

}

void Aes::InvShiftRows() {

    u8 temp[4*4];
    int i,j;
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            temp[4*i+j]=State[i][j];
        }
    }
    for(i=1;i<4;i++) {
        for(j=0;j<4;j++) {
            //if(i==1)State[i][j]=temp[4*i+(j-1)%4]; 在此犯了一个错误 -1%4=-1 而不是3，所以采用了下面再加一个4的做法
            if(i==1)State[i][j]=temp[4*i+(j+3)%4];            //第一行右移1位 j-1+4=j+3
            else if(i==2)State[i][j]=temp[4*i+(j+2)%4];        //第二行右移2位 j-2+4=j+2
            else if(i==3)State[i][j]=temp[4*i+(j+1)%4];        //第三行右移3位 j-3+4=j+2
        }
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::MixColumns() {

    u8 temp[4*4];
    int i,j;
    //2 3 1 1 列混淆矩阵 Page107
    //1 1 2 3
    //1 2 3 1
    //3 1 1 2
    for(j=0;j<4;j++) {
        for(i=0;i<4;i++) {
            temp[4*i+j]=State[i][j];
        }
    }
    for(j=0;j<4;j++) {
        State[0][j] = (u8) ( (int)gfmultby02(temp[0+j]) ^ (int)gfmultby03(temp[4*1+j]) ^
                (int)gfmultby01(temp[4*2+j]) ^ (int)gfmultby01(temp[4*3+j]) );
        State[1][j] = (u8) ( (int)gfmultby01(temp[0+j]) ^ (int)gfmultby02(temp[4*1+j]) ^
                (int)gfmultby03(temp[4*2+j]) ^ (int)gfmultby01(temp[4*3+j]) );
        State[2][j] = (u8) ( (int)gfmultby01(temp[0+j]) ^ (int)gfmultby01(temp[4*1+j]) ^
                (int)gfmultby02(temp[4*2+j]) ^ (int)gfmultby03(temp[4*3+j]) );
        State[3][j] = (u8) ( (int)gfmultby03(temp[0+j]) ^ (int)gfmultby01(temp[4*1+j]) ^
                (int)gfmultby01(temp[4*2+j]) ^ (int)gfmultby02(temp[4*3+j]) );
    }

}
void Aes::InvMixColumns() {

    u8 temp[4*4];
    int i,j;
    // copy State into temp[]
    for (i = 0; i < 4; i++) {
        //0e 0b 0d 09 逆变换矩阵 Page108
        //09 0e 0b 0d
        //0d 09 0e 0b
        //0b 0d 09 0e
        for (j = 0; j < 4; j++)  {
            temp[4*i+j] = State[i][j];
        }
    }

    for (j = 0; j < 4; j++) {
        State[0][j] = (u8) ( (int)gfmultby0e(temp[j]) ^ (int)gfmultby0b(temp[4+j]) ^
                (int)gfmultby0d(temp[4*2+j]) ^ (int)gfmultby09(temp[4*3+j]) );
        State[1][j] = (u8) ( (int)gfmultby09(temp[j]) ^ (int)gfmultby0e(temp[4+j]) ^
                (int)gfmultby0b(temp[4*2+j]) ^ (int)gfmultby0d(temp[4*3+j]) );
        State[2][j] = (u8) ( (int)gfmultby0d(temp[j]) ^ (int)gfmultby09(temp[4+j]) ^
                (int)gfmultby0e(temp[4*2+j]) ^ (int)gfmultby0b(temp[4*3+j]) );
        State[3][j] = (u8) ( (int)gfmultby0b(temp[j]) ^ (int)gfmultby0d(temp[4+j]) ^
                (int)gfmultby09(temp[4*2+j]) ^ (int)gfmultby0e(temp[4*3+j]) );
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
u8 Aes::gfmultby01(u8 b) {
    return b;
}

u8 Aes::gfmultby02(u8 b) {
    if (b < 0x80)
        return (u8)(int)(b <<1);
    else
        return (u8)( (int)(b << 1) ^ (int)(0x1b) );
}

u8 Aes::gfmultby03(u8 b) {
    return (u8) ( (int)gfmultby02(b) ^ (int)b );
}

u8 Aes::gfmultby09(u8 b) {
    return (u8)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^ (int)b );
}

u8 Aes::gfmultby0b(u8 b) {
    return (u8)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^
                            (int)gfmultby02(b) ^ (int)b );
}

u8 Aes::gfmultby0d(u8 b) {
    return (u8)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^
                            (int)gfmultby02(gfmultby02(b)) ^ (int)(b) );
}

u8 Aes::gfmultby0e(u8 b) {
    return (u8)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^
                            (int)gfmultby02(gfmultby02(b)) ^(int)gfmultby02(b) );
}
