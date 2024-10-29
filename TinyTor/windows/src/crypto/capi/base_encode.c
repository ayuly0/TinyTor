#include <crypto/capi/base_encode.h>
#include <windows.h>
#include <wincrypt.h>

void BaseEncodeImpl(DWORD dwFlags, const PBYTE pbInput, DWORD dwInputSize, LPSTR pszOutput, PDWORD dwOutputSize)
{
	if (!pszOutput)
	{
		*dwOutputSize = 0;
	}
	if (!CryptBinaryToString(pbInput, dwInputSize, dwFlags, NULL, dwOutputSize)) {
        return;
    }

    if (!CryptBinaryToString(pbInput, dwInputSize, dwFlags, pszOutput, dwOutputSize)) {
        return;
    }
}

void BaseDecodeImpl(DWORD dwFlags, LPSTR pbInput, DWORD dwInputSize, PBYTE pszOutput, PDWORD dwOutputSize)
{
	if (!pszOutput)
	{
		*dwOutputSize = 0;
	}

	if (CryptStringToBinary(pbInput, dwInputSize, dwFlags, NULL, dwOutputSize, NULL, NULL))
	{
		return;
	}

	if (CryptStringToBinary(pbInput, dwInputSize, dwFlags, pszOutput, dwOutputSize, NULL, NULL))
	{
		return;
	}
}