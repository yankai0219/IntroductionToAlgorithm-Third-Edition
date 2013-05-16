
/*
* CopyRight By    YK
* Data:           2013/05/10
* Modified Data:  2013/05/13
*/

#include "double_linked_list.h"

void 
err_exit(char *fmt,...)
{
    va_list va;

    va_start(va,fmt);
    printf("%s:%d",__FILE__,__LINE__);
    vprintf(fmt,va);
    va_end(va);
    exit(0);
}

dll_t *
init_double_link( )
{
    dll_t *dll;
    dll = (dll_t*)calloc(1,sizeof(dll_t));
    if(dll == NULL) {
        err_exit("calloc error\n");
    }
    
    dll->prev = dll;/*??prev == NULL or prev = itself??*/
    dll->next = dll;

    return dll;
}

int  
insert_elem_double_link(dll_t *dll, dll_t *new_elem)
{

    dll_t *last_elem;
 
    last_elem = search_last_element_dll(dll);

    new_elem->next         = last_elem->next;
    last_elem->next->prev  = new_elem;
    last_elem->next        = new_elem;
    new_elem->prev         = last_elem;
   
    return 0; 
}

int  
insert_key_double_link(dll_t *dll, int key)
{
    dll_t *last_elem,*new_elem;
 
    new_elem = (dll_t*)calloc(1,sizeof(dll_t));
    if(new_elem == NULL) {
        err_exit("calloc error\n");
    }  
    new_elem->key = key;
      
    last_elem = search_last_element_dll(dll);
    new_elem->next         = last_elem->next;
    last_elem->next->prev  = new_elem;
    last_elem->next        = new_elem;
    new_elem->prev         = last_elem;
    
    return 0;
}

dll_t * 
search_last_element_dll(dll_t *dll)
{
    /*
    dll_t * tmp;

    tmp = dll;

    while(tmp->next != dll) {
        tmp = tmp->next;
    }

    return tmp;
    */
    return dll->prev;
}

dll_t * 
search_double_link(dll_t *dll, int value)
{
     dll_t *tmp;

     tmp = dll->next;

     while(tmp != dll) {/*traverse*/
         if(tmp->key == value) {
            break; 
         }
         tmp = tmp->next;
     }

     if(tmp == dll) {/*after traverse, no equal element exists,so return NULL*/
        tmp = NULL;
     }

     return tmp;

}

int 
delete_element(dll_t *dll, int value)
{
    int res;
    dll_t *tmp;
   
    tmp = dll->next;
    
     while(tmp != dll) {/*traverse*/
         if(tmp->key == value) {
            break; 
         }
         tmp = tmp->next;
     }

     if(tmp != dll) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);

        res = 1;
     } else {
        printf("NO %d value\n",value);
        res = 0;
     }

     return res;
}

void 
traverse(dll_t *dll)
{
    int i;
    dll_t *tmp;
    
    i = 0;
    tmp = dll->next;

    while(tmp != dll) {
        printf("%dth key:%d\n",i,tmp->key);
        i++;
        tmp = tmp->next; 
   }
 
    return;
}
