#include "../include/cstack.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
void cstack_init(CStack_Dynamic *p)
{
    if (p == NULL)
    {
        perror("cstack-said-> Invalid ptr to stack");
        exit(EXIT_FAILURE);
    }

    if (*p->data != NULL)
    {
        perror("cstack-said-> This stack is already open");
        free(p->data);
        exit(EXIT_FAILURE);
    }

    p->data = NULL;
    p->size = 0;
    return;
}

void cstack_end(CStack_Dynamic *p)
{
    if (p == NULL)
    {
        perror("cstack-said-> Invalid pointer to free");
        exit(EXIT_FAILURE);
    }

    if (*p->data == NULL)
    {
        perror("cstack-said-> Cannot free an NULL pointer");
        exit(EXIT_FAILURE);
    }

    free(p->data);
    p->size = 0;
}

void cstack_push(CStack_Dynamic *p, int data)
{
    if (p == NULL)
    {
        perror("cstack-said-> Invalid pointer to push");
        exit(EXIT_FAILURE);
    }

    if (p->data == NULL)
    {
        p->data = (int *)malloc(sizeof(int));
        if (!p->data)
        {
            perror("cstack-said-> Running out of memory, cannot malloc.");
            exit(EXIT_FAILURE);
        }

        p->data[0] = data;
        p->size++;
    }

    else
    {
        p->data = (int *)realloc(p->data, sizeof(int) * ++p->size);
        if (!p->data)
        {
            perror("cstack-said-> Running out of memory, cannot malloc.");
            exit(EXIT_FAILURE);
        }

        p->data[p->size - 1] = data;
    }
}
void cstack_pop(CStack_Dynamic *p)
{
    if (p == NULL)
    {
        perror("cstack-said-> Invalid pointer to free");
        exit(EXIT_FAILURE);
    }

    if (p->size == 0)
    {
        perror("cstack-said-> Cannot pop with 0 height");
    }

    p->data[p->size - 1] = -1;
    p->data = (int *)realloc(p->data, sizeof(int) * --p->size);
}
