/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "queue.h"
#include "common.h"

int main(int argc, char ** argv)
{
    circular_buffer cb;
    elem_type elem = {0};

    int test_buffer_size = 10; /*arbitrary size*/
    cbinit(&cb, test_buffer_size);
   
    for(elem.value = 0; elem.value < 3*test_buffer_size; elem.value++) {
        cb_write(&cb, &elem);
    }

    while(!cb_is_empty(&cb)) {
        cb_read(&cb, &elem);
        printf("%d\n",elem.value);
    }

    cbfree(&cb);
    return 0;
}
