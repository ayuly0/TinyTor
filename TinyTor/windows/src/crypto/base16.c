#include <crypto/base16.h>

void Base16Encode(PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseEncodeImpl(CRYPT_STRING_HEX, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}

void Base16Decode(LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput)
{
    DWORD dwOutputSize = 0;
    BaseDecodeImpl(CRYPT_STRING_HEX, pbInput, dwInputSize, pszOutput, &dwOutputSize);
}