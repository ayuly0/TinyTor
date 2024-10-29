#ifndef TINY_TOR_CRYPTO_AES_H
#define TINY_TOR_CRYPTO_AES_H

#include <windows.h>
#include <bcrypt.h>

#define AES_KEY_SIZE 256
#define BLOCK_SIZE 16

typedef struct AESCryptor
{
	BYTE Key[AES_KEY_SIZE / 8];
	BYTE Iv[BLOCK_SIZE];

	BCRYPT_ALG_HANDLE hAlg;
    BCRYPT_KEY_HANDLE hKey;

	void (*SetKey)(struct AESCryptor* self, PBYTE key);
	void (*SetIv)(struct AESCryptor* self, PBYTE iv);

	void (*Encrypt)(struct AESCryptor* self, PBYTE data, DWORD dwDataSize, PBYTE dest, DWORD dwDestSize);
	void (*Decrypt)(struct AESCryptor* self, PBYTE data, DWORD dwDataSize, PBYTE dest, DWORD dwDestSize);
	NTSTATUS (*Initialize)(struct AESCryptor* self);
    void (*Cleanup)(struct AESCryptor* self);
} AESCryptor;

#endif // !TINY_TOR_CRYPTO_AES_H