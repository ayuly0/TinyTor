#include <crypto/base64.h>

void Base64Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseEncodeImpl(CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}

void Base64Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseDecodeImpl(CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}