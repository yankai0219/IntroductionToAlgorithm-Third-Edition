
/*
* CopyRight By YK
* Data:2013/05/12
*/


#include "common.h"
#include "queue.h"


void err_exit(char *fmt,...)
{
    va_list va;

    va_start(va,fmt);
    printf("%s:%d",__FILE__,__LINE__);
    vprintf(fmt,va);
    va_end(va);
    exit(0);
}

void 
cbinit(circular_buffer *cb, int size)
{
    cb->size   = size + 1;
    cb->start  = 0;
    cb->end    = 0;
    cb->elems  = (elem_type*)calloc(cb->size, sizeof(elem_type));
    if (cb->elems == NULL) {
        err_exit("calloc error\n");
    } 
}

void 
cbfree(circular_buffer *cb)
{
    free(cb->elems);
}

int 
cb_is_full(circular_buffer *cb)
{
    return (cb->end + 1) % cb->size == cb->start;
}

int 
cb_is_empty(circular_buffer *cb)
{
    return cb->end == cb->start;
}

void 
cb_write(circular_buffer *cb, elem_type *elem)
{
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1) % cb->size;
    if(cb->end == cb->start) {
        cb->start = (cb->start + 1) % cb->size ; /*full, overwrite*/
    }
}

void 
cb_read(circular_buffer *cb, elem_type *elem)
{
    *elem = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
}
