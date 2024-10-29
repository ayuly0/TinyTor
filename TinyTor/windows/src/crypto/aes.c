#include <crypto/aes.h>
#include <crt0/ntstatus.h>

NTSTATUS AESCryptorInitialize(AESCryptor* self) {
    // self->hKey = (BCRYPT_KEY_HANDLE*)malloc(sizeof(BCRYPT_KEY_HANDLE));
    NTSTATUS status = BCryptOpenAlgorithmProvider(&self->hAlg, BCRYPT_AES_ALGORITHM, NULL, 0);
    if (!BCRYPT_SUCCESS(status)) return status;

    printf("init hKey 0x%p\nIv 0x%p\n", &self->hKey, &self->Iv);
    status = BCryptGenerateSymmetricKey(self->hAlg, &self->hKey, NULL, 0, self->Key, sizeof(self->Key), 0);
    return status;
}

void AESCryptorCleanup(AESCryptor* self) {
    if (self->hKey) {
        BCryptDestroyKey(self->hKey);
        self->hKey = NULL;
    }
    if (self->hAlg) {
        BCryptCloseAlgorithmProvider(self->hAlg, 0);
        self->hAlg = NULL;
    }
}

void AESCryptorSetKey(AESCryptor* self, PBYTE key) {
    memcpy(self->Key, key, sizeof(self->Key));
}

void AESCryptorSetIv(AESCryptor* self, PBYTE iv) {
    memcpy(self->Iv, iv, sizeof(self->Iv));
}

void AESEncrypt(AESCryptor* self, PBYTE data, DWORD dwDataSize, PBYTE dest, DWORD dwDestSize)
{
    DWORD cbData = 0;
    DWORD blockSize = BLOCK_SIZE;
    NTSTATUS status;

    if (dwDestSize < dwDataSize + blockSize) {
        printf("Destination buffer is too small\n");
        return;
    }

    if (self->Iv == NULL || &self->hKey == NULL) {
        printf("Initialization vector or key is not set\n");
        return;
    }

    if (data == NULL || dest == NULL) {
        printf("Data or Dest is not set\n");
        return;
    }

    printf("hKey 0x%p\ndata 0x%p\nIv 0x%p\ndes 0x%p\n", &self->hKey, data, &self->Iv, dest);

    status = BCryptEncrypt(
        &self->hKey,
        data,
        dwDataSize,
        NULL,
        self->Iv,
        blockSize,
        dest,
        dwDestSize,
        &cbData,
        0
    );

    if (!BCRYPT_SUCCESS(status)) {
        printf("Encryption failed: 0x%x\n", status);
    } else {
        printf("Encryption succeeded, encrypted data size: %lu bytes\n", cbData);
    }
}

void AESDecrypt(struct AESCryptor* self, PBYTE data, DWORD dwDataSize, PBYTE dest, DWORD dwDestSize)
{
	
}

AESCryptor* AESCryptorCreate(PBYTE key, PBYTE iv) {
    AESCryptor* cryptor = (AESCryptor*)malloc(sizeof(AESCryptor));
    if (cryptor == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    cryptor->SetKey = AESCryptorSetKey;
    cryptor->SetIv = AESCryptorSetIv;
    cryptor->Encrypt = AESEncrypt;
    cryptor->Decrypt = AESDecrypt;
    cryptor->Initialize = AESCryptorInitialize;
    cryptor->Cleanup = AESCryptorCleanup;

    cryptor->SetKey(cryptor, key);
    cryptor->SetIv(cryptor, iv);

    if (cryptor->Initialize(cryptor) != STATUS_SUCCESS) {
        printf("Failed to initialize AESCryptor\n");
        return -1;
    }
    printf("Success to initialize AESCryptor\n");

    printf("create hKey 0x%p\nIv 0x%p\n", &cryptor->hKey, &cryptor->Iv);
    return cryptor;
}