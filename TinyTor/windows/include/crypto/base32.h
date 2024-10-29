#ifndef TINY_TOR_CRYPTO_BASE32_H
#define TINY_TOR_CRYPTO_BASE32_H

#include <windows.h>
#include <crypto/capi/base_encode.h>

void Base32Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput);

void Base32Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput);

#endif // !TINY_TOR_CRYPTO_BASE32_H