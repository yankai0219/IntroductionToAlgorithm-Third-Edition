
/*
* CopyRight By YK
* Data:2013/05/10
*/

#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_  

#include "common.h"

typedef struct dll_s dll_t;

struct dll_s {
    dll_t   *prev;
    dll_t   *next;
    int      key;
};

int     insert_elem_double_link(dll_t *dll, dll_t *new_elem);
int     insert_key_double_link(dll_t *dll, int key);
int     delete_element(dll_t *dll, int value);
void    err_exit(char *fmt, ...);
void    traverse(dll_t *dll);
dll_t  *init_double_link(void);
dll_t  *search_last_element_dll(dll_t *dll);
dll_t  *search_double_link(dll_t *dll, int value);


#endif 
