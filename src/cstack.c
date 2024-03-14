#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>
#include "../include/cstack.h"

void cstack_init(CStack *p)
{
    if (p != NULL)
    {
        p->data = NULL;
        p->size = CSTACK_BOTLIM;
        return;
    }
    perror("ctack-said-> Can't init an invalid pointer");
    return;
}

void cstack_end(CStack *p)
{
    if (p != NULL)
    {
        free(p->data);
        return;
    }
    perror("cstack-said-> Can't end an invalid pointer");
}

void cstack_push(CStack *p, void *data)
{
    if (p == NULL)
    {
        perror("cstack-said-> Can't add data to an invalid pointer");
        return;
    }

    if (data == NULL)
    {
        perror("cstack-said-> Can't add new data if data is NULL");
        return;
    }

    if (p->data == NULL)
    {
        p->data = malloc(sizeof(void *));
        if (!p->data)
        {
            perror("cstack-said-> Running out of memory.");
            return;
        }
        p->size = 1;
        memcpy(p->data, &data, sizeof(void *));
    }
    else
    {
        p->data = realloc(p->data, (p->size + 1) * sizeof(void *));
        if (!p->data)
        {
            perror("cstack-said-> Running out of memory.");
            return;
        }
        memcpy(p->data + p->size, &data, sizeof(void *));
        p->size++;
    }
}
