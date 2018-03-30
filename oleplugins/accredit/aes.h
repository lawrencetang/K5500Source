#ifndef AES_H
#define AES_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char u8;
typedef char n8;
typedef unsigned short u16;
typedef short n16;
typedef unsigned int u32;
typedef int n32;


//enum KeySize { Bits128, Bits192, Bits256 }; // key size, in bits, for construtor
#define Bits128    16
#define Bits192    24
#define Bits256    32

// Advanced Encryption Standard
class Aes
{
public:
    Aes();
    Aes(int keySize, u8* keyu8s);
    ~Aes();

    // encipher 16-bit input
    void Cipher(u8* input, u8* output);
    // decipher 16-bit input
    void InvCipher(u8* input, u8* output);

private:
    int Nb; // block size in 32-bit words. Always 4 for AES. (128 bits).
    int Nk; // key size in 32-bit words. 4, 6, 8. (128, 192, 256 bits).
    int Nr; // number of rounds. 10, 12, 14.

    u8 w[16*15];
    u8 key[32];
    u8 State[4][4];

    void SetNbNkNr(int keySize);
    void AddRoundKey(int round); //轮密钥加
    void Subu8s();               //S盒字节代换
    void InvSubu8s();            //逆S盒字节代换
    void ShiftRows();            //行移位
    void InvShiftRows();
    void MixColumns();           //列混淆
    void InvMixColumns();
    u8 gfmultby01(u8 b);
    u8 gfmultby02(u8 b);
    u8 gfmultby03(u8 b);
    u8 gfmultby09(u8 b);
    u8 gfmultby0b(u8 b);
    u8 gfmultby0d(u8 b);
    u8 gfmultby0e(u8 b);
    void KeyExpansion();                         //密钥扩展
    u8* SubWord(u8* word); //密钥S盒字代换
    u8* RotWord(u8* word); //密钥移位
};

#endif // AES_H
