
/*
 * yk_hash.h
 *
 *  Created on: Nov 12, 2012
 *      Author: root
 */

#ifndef YK_HASH_H_
#define YK_HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdarg.h>

#define _PRINT_DEBUG_ 0
#if _PRINT_DEBUG_
#define printf_debug(...) printf(__VA_ARGS__)
#else
#define printf_debug(...)
#endif

typedef struct hash_key_s    hash_key_t;
typedef struct hash_elem_s   hash_elem_t;
typedef struct hash_table_s  hash_table_t;

typedef enum{
    FALSE=0,
    TRUE=1
}STATUS;

struct hash_key_s {
    int key;
};


struct hash_elem_s{
    hash_key_t   key;
    hash_elem_t *next;
};

//hash table
struct hash_table_s{
    int          hash_slot_number;
    hash_elem_t **hash_tb;
    
};

void            err_exit(char*fmt, ...);
STATUS          insert_data_into_hash(hash_table_t * hash_tb, int data);
STATUS          delete_data_from_hash(hash_table_t * hash_tb, int data);
STATUS          output_data_in_hash(hash_table_t * hash_tb);
hash_table_t   *hash_table_init(int slot_num);
unsigned long   HashInt(hash_table_t *hash_table, int data);
hash_elem_t    *find_data_from_hash(hash_table_t * hash_tb, int data);
void            hash_table_free(hash_table_t *hash_tb);

#endif /* YK_HASH_H_ */
