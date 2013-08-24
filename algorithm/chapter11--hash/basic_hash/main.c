

/*
 * yk_hash_main.c
 *
 *  Created on: Nov 12, 2012
 *  aim:this project is a typical implementation of hash algorithm
 */

#include "hash.h"

int main()
{
    int           i,slot_num;
    hash_table_t *hashTb;
    int array[]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,8,9,17,18,19,20,88,98,58,78,68};

    slot_num = 10;
    if( NULL == (hashTb = hash_table_init(slot_num)) ){
       err_exit("hash_table_init error\n");	
    }

    for(i = 0; i < sizeof(array)/sizeof(int);i++){
        insert_data_into_hash(hashTb,array[i]);
    }

    printf("output all data\n");
    output_data_in_hash(hashTb);
    delete_data_from_hash(hashTb,88);
    printf("after delete 88\n");
    output_data_in_hash(hashTb);
  
    hash_table_free(hashTb); 
    return 0;

}

