#ifndef CSTACK_H
#define CSTACK_H
#include <stdbool.h>
typedef struct cstack
{
    int *data; // Dynamic memory allocation.
    unsigned int size;
} CStack_Dynamic;

void cstack_init(CStack_Dynamic *p);
void cstack_end(CStack_Dynamic *p);
void cstack_push(CStack_Dynamic *p, int data);
void cstack_pop(CStack_Dynamic *p);
bool cstack_is_full(CStack_Dynamic *p);

#endif