
/*
* CopyRight By YK
* Data:2013/05/12
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_  

#include "common.h"
typedef struct {
    int value;
} elem_type;

typedef struct {
    int         size;         /*maximum number of elements  */
    int         start;        /*index of oldest element     */
    int         end;          /*vector of elements          */
    elem_type  *elems;        /*vector of elements          */
}circular_buffer;

int  cb_is_full(circular_buffer *cb);
int  cb_is_empty(circular_buffer *cb);
void err_exit(char *fmt, ...);
void cbinit(circular_buffer *cb, int size);
void cbfree(circular_buffer *cb);
void cb_write(circular_buffer *cb, elem_type *elem);
void cb_read(circular_buffer *cb, elem_type *elem);


#endif 
