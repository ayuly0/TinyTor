#include <crypto/aes.h>
#include <stdio.h>
#include <windows.h>
#include <intrin.h>
#include <wincrypt.h>
#include <winnt.h>
#include <winternl.h>

void GenerateRandomBytes(BYTE* buffer, DWORD length) {
    HCRYPTPROV hProv;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        printf("CryptAcquireContext failed: %lu\n", GetLastError());
        exit(1);
    }
    if (!CryptGenRandom(hProv, length, buffer)) {
        printf("CryptGenRandom failed: %lu\n", GetLastError());
        exit(1);
    }
    CryptReleaseContext(hProv, 0);
}

extern int main()
{
    LPSTR commandLine = GetCommandLineA();

    printf("Command Line: %s\n", commandLine);
	BYTE plaintext[16] = "1234567891012141";
    BYTE ciphertext[100];
	DWORD outSize = 100;
	BYTE key[256/8]; // 256 bits
    BYTE iv[16];  // 128 bits

    GenerateRandomBytes(key, sizeof(key));
    GenerateRandomBytes(iv, sizeof(iv));

    printf("AES Key: ");
    for (int i = 0; i < sizeof(key); i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < sizeof(iv); i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

	AESCryptor* cryptor = AESCryptorCreate(key, iv);
	// printf("0x%p", plaintext);
    printf("main1 hKey 0x%p\nIv 0x%p\n", &cryptor->hKey, &cryptor->Iv);
	AESEncrypt(cryptor, plaintext, sizeof(plaintext), ciphertext, sizeof(ciphertext));
    printf("main2 hKey 0x%p\nIv 0x%p\n", &cryptor->hKey, &cryptor->Iv);
	printf("0x%p", *ciphertext);
}

extern void _RTC_CheckStackVars(){}
extern void _RTC_InitBase(){}
extern void _RTC_Shutdown(){}