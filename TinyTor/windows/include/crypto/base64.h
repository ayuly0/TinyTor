#ifndef TINY_TOR_CRYPTO_BASE64_H
#define TINY_TOR_CRYPTO_BASE64_H

#include <windows.h>
#include <crypto/capi/base_encode.h>

void Base64Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput);

void Base64Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput);

#endif // !TINY_TOR_CRYPTO_BASE64_H