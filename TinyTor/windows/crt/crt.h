#ifndef TINY_TOR_CRT
#define TINY_TOR_CRT


FILE _iob[] = {*stdin, *stdout, *stderr};

extern "C" FILE * __cdecl __iob_func(void)
{
    return _iob;
}

#endif // !TINY_TOR_CRT