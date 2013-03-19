#include "basiclib.h"
#include "except.h"
#define T Except_T

Except_Frame *Except_stack = NULL;       //define

/*******************************
*如果TRY调用Except_raise(),则一般p
*不为空，此时将错误信息写入错误栈栈顶；
*如果FINALLY调用，则p一般为空，
*即表示没有对应的错误处理程序
********************************/
void Except_raise(const T *e, const char *file, int line)
{
    Except_Frame *p = Except_stack;
    assert(e);
    if(p == NULL)
    {
        fprintf(stderr, "Uncatched Exception");
        if(e->reason)
            fprintf(stderr, "%s", e->reason);
        if(file && line > 0)
            fprintf(stderr, " raised at %s:%d\n", file, line);
        fprintf(stderr, "aborting...\n");
        fflush(stderr);
        abort();

    }

    p->exception = e;
    p->file = file;
    p->line = line;
    Except_stack = Except_stack->prev;
    longjmp(p->env, Except_raised);
}
