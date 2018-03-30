#ifndef AESI_H
#define AESI_H

#include "aes.h"

typedef unsigned long DWORD;
typedef unsigned char UCHAR,*PUCHAR;
typedef void *PVOID,*LPVOID;
typedef DWORD *PDWORD,*LPDWORD;

class AesI
{
public:
    AesI();
    ~AesI();

    void initializePrivateKey(DWORD KeySize,UCHAR *KeyBytes);                        //AES 密钥初始化
    DWORD useAesEncrypt(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer);            //AES 加密数据
    DWORD useAesDecode(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer);             //AES 解密数据

private:
    Aes * m_lpAes;
};

#endif // AESI_H
