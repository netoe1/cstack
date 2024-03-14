#ifndef CSTACK_H
#define CSTACK_H
#define CSTACK_BOTLIM 0
struct CSTACK
{
    void *data; // Data to
    int size;
};

typedef struct CSTACK CStack;

void cstack_init(CStack *p);
void cstack_end(CStack *p);
void cstack_push(CStack *p, void *data);
#endif