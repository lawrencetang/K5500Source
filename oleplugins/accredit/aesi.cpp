#include "aesi.h"

AesI::AesI() {
    m_lpAes=NULL;
    initializePrivateKey(16,(unsigned char*)"\x79\x76\x68\x6B\x77\x66\x6E\x68\x72\x65\x73\x63\x6C\x6B\x70\x6E");
}

AesI::~AesI() {
    if (m_lpAes) {
        delete m_lpAes;
        m_lpAes = NULL;
    }
}

/**
 * @brief AesI::initializePrivateKey
 * @param KeySize
 * @param KeyBytes
 */
void AesI::initializePrivateKey(DWORD KeySize, UCHAR *KeyBytes) {

    if (m_lpAes) {
        delete m_lpAes;
        m_lpAes=NULL;
    }
    m_lpAes=new Aes(KeySize,KeyBytes);
}

/**
 * @brief AesI::useAesEncrypt
 * @param InBuffer
 * @param InLength
 * @param OutBuffer
 * @return
 */
DWORD AesI::useAesEncrypt(LPVOID InBuffer, DWORD InLength, LPVOID OutBuffer) {

    DWORD OutLength=0;
    if (m_lpAes==NULL||OutBuffer==NULL) {
        return 0;
    }

    UCHAR *lpCurInBuff=(UCHAR *)InBuffer;
    UCHAR *lpCurOutBuff=(UCHAR *)OutBuffer;
    long blocknum=InLength/16;
    long leftnum=InLength%16;
    for(long i=0; i<blocknum; i++) {
        m_lpAes->Cipher(lpCurInBuff,lpCurOutBuff);
        lpCurInBuff+=16;
        lpCurOutBuff+=16;
        OutLength+=16;
    }
    // 多余出leftnum 字节 则加密时 多出16-leftnum 个字节
    if(leftnum) {
        UCHAR inbuff[16];
        memset(inbuff,0,16);
        memcpy(inbuff,lpCurInBuff,leftnum);
        m_lpAes->Cipher(inbuff,lpCurOutBuff);
        lpCurOutBuff+=16;
        OutLength+=16;
    }
    // 新增16个字节，用以确定增加的字节数
    UCHAR extrabuff[16];
    memset(extrabuff,0,16);
    // 多出16+(16-leftnum)%16个字节
    *((LPDWORD)extrabuff)=16+(16-leftnum)%16;
    m_lpAes->Cipher(extrabuff,lpCurOutBuff);
    OutLength+=16;
    return OutLength;
}

/**
 * @brief AesI::useAesDecode
 * @param InBuffer
 * @param InLength
 * @param OutBuffer
 * @return
 */
DWORD AesI::useAesDecode(LPVOID InBuffer, DWORD InLength, LPVOID OutBuffer)
{
    DWORD OutLength=0;
    if (m_lpAes==NULL||OutBuffer==NULL) {
        return 0;
    }
    UCHAR *lpCurInBuff=(UCHAR *)InBuffer;
    UCHAR *lpCurOutBuff=(UCHAR *)OutBuffer;
    long blocknum=InLength/16;
    long leftnum=InLength%16;
    if(leftnum) {
        return 0;
    }
    for(long i=0;i<blocknum;i++) {
        m_lpAes->InvCipher(lpCurInBuff,lpCurOutBuff);
        lpCurInBuff+=16;
        lpCurOutBuff+=16;
        OutLength+=16;
    }

    UCHAR *lpExtraInBuff=lpCurOutBuff-16;
    DWORD dwExtraBytes=*((LPDWORD)lpExtraInBuff);
    return (OutLength-dwExtraBytes);
}

