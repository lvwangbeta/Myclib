#include "basiclib.h"
#include "except.h"
#include "mem.h"

const Except_T Mem_failed = {"Out of memeory\n"};

void *Mem_Malloc(long nbytes, const char *file, int line)
{
    void *p;
    assert(nbytes > 0);
    p = malloc(nbytes);
    if(p == NULL)           //raise mem_failed exception
    {
        if(file == NULL)
            RAISE(Mem_failed);
        else
            Except_raise(&Mem_failed, file, line);
    }
    return p;
}
void *Mem_Alloc(long count, long nbytes, const char *file, int line)
{
    void *p;
    assert(count > 0);
    assert(nbytes > 0);
    p = calloc(count, nbytes);
    if(p == NULL)
    {
        if(file == NULL)
            RAISE(Mem_failed);
        else
            Except_raise(&Mem_failed, file, line);
    }
    return p;
}
void  Mem_Free(void *p, const char *file, int line)
{
    if(p)
        free(p);
}
