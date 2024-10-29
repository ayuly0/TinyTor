#ifndef TINY_TOR_CRYPTO_CAPI_BASE_ENCODE_H
#define TINY_TOR_CRYPTO_CAPI_BASE_ENCODE_H

#include <windows.h>
#include <wincrypt.h>

void BaseEncodeImpl(DWORD dwFlags, PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput, PDWORD dwOutputSize);

void BaseDecodeImpl(DWORD dwFlags, LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput, PDWORD dwOutputSize);

#endif // !TINY_TOR_CRYPTO_CAPI_BASE_ENCODE_H