#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED
#include "except.h"

extern const Except_T Mem_failed;
extern void *Mem_Malloc(long nbytes, const char *file, int line);
extern void *Mem_Alloc(long count, long nbytes, const char *file, int line);
extern void  Mem_Free(void *p, const char *file, int line);


#define MALLOC(nbytes) Mem_Malloc(nbytes, __FILE__, __LINE__)
#define ALLOC(count, nbytes) Mem_Alloc(count, nbytes, __FILE__, __LINE__)
#define Free(p) (Mem_Free((p), __FILE__, __LINE__), (p)=0)

#define NEW(p) ((p) = MALLOC((long)sizeof(*p)))
#define NEW0(p) ((p) = ALLOC(1, (long)sizeof(*p)))

#endif // MEM_H_INCLUDED
