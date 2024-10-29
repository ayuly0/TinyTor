#include <crypto/base32.h>

void Base32Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseEncodeImpl(CRYPT_STRING_BASE32 | CRYPT_STRING_NOCRLF, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}

void Base32Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseDecodeImpl(CRYPT_STRING_BASE32 | CRYPT_STRING_NOCRLF, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}