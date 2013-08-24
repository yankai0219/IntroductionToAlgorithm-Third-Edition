/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "double_linked_list.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int i,len;
    dll_t *dll;
    int array[] = {23,4,34,2,134};
     
    len = sizeof(array)/sizeof(int);

    dll = init_double_link();
    for (i = 0; i < len; i++) {
        insert_key_double_link(dll,array[i]);
    }    
    printf("traverse\n");
    traverse(dll);
    printf("after DELETE 23traverse\n");
    delete_element(dll,23);
    traverse(dll);
    printf("after DELETE 2 traverse\n");
    delete_element(dll,2);
    traverse(dll);
    delete_element(dll,55);
    traverse(dll);
    return 0;
}
