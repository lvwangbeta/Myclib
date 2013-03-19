#ifndef EXCEPT_H_INCLUDED
#define EXCEPT_H_INCLUDED
#include <setjmp.h>
#define T Except_T
typedef struct T
{
   const char *reason;              //*reason can not be changed
}T;

typedef struct Except_Frame Except_Frame;
struct Except_Frame
{
    Except_Frame *prev;             //指向前一帧
    jmp_buf env;                    //setjmp longjmp使用
    const char *file;
    int line;
    const T *exception;
};
                                    //异常状态位
enum {Except_entered=0, Except_raised, Except_handled, Except_finalized };
extern Except_Frame *Except_stack;  //指向栈顶,declare

void Except_raise(const T *e, const char *file, int line);

/**********************************
*RAISE(e) 调用Except_raise异常处理函数
*该函数会在栈顶的异常帧中填写exception,
*file, line 字段
***********************************/
#define RAISE(e) Except_raise(&(e), __FILE__, __LINE__)

/***********************************
*TRY将一个Except_frame结构压入异常栈，并调用
*setjmp()，setjmp第一次返回将Except_flag
*设置为0(Except_entered),当发生异常时setjmp
*还会二次返回
************************************/
#define TRY do{ \
            volatile int Except_flag; \
            Except_Frame Except_frame; \
            Except_frame.prev = Except_stack; \
            Except_stack = &Except_frame; \
            Except_flag = setjmp(Except_frame.env); \
            if(Except_flag == Except_entered) \
            {

#define EXCEPT(e) \
                if(Except_flag == Except_raised) \
                    Except_stack = Except_stack->prev; \
            } \
            else if(Except_frame.exception == &(e)) \
            { \
                Except_flag = Except_handled;

#define ELSE \
                if(Except_flag == Except_entered) \
                    Except_stack = Except_stack->prev; \
            } \
            else \
            { \
                Except_flag = Except_handled;

#define FINALLY \
                if(Except_flag == Except_entered) \
                    Except_stack = Except_stack->prev; \
            } \
            { \
                if(Except_flag == Except_entered) \
                    Except_flag = Except_finalized;

#define END_TRY \
                if(Except_flag == Except_entered) \
                    Except_stack = Except_stack->prev; \
            } \
            if(Except_flag == Except_raised) \
                Except_raise(Except_frame.exception, Except_frame.file, Except_frame.line);\
            }while(0)


#undef T
#endif                              // EXCEPT_H_INCLUDED
