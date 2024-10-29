#ifndef TINY_TOR_CRYPTO_BASE16_H
#define TINY_TOR_CRYPTO_BASE16_H

#include <windows.h>
#include <crypto/capi/base_encode.h>

void Base16Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput);

void Base16Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput);

#endif // !TINY_TOR_CRYPTO_BASE16_H