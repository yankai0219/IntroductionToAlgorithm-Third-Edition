
/*
 * yk_hash.h
 *
 *  Created on: Nov 13, 2012
 *  Author: YanKai
*
*   Modified Data:2013/05/11
 */

#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#define   BUCKET_LEN 47

typedef char * type;

typedef enum{
	FALSE=0,
	TRUE
}STATUS;

typedef struct _NODE{
	type key;
	int key_len;
	unsigned int occur_count;
	struct _NODE *next;
}NODE;

typedef struct _HASH_TABLE{
	unsigned int hit_count;
	NODE * keys_chain;
}HASH_TABLE;

/*hash table length is fixed (value is BUCKET_LEN)*/
HASH_TABLE* yk_hash_table_init();

/* A Simple Hash Function */
unsigned int yk_simple_hash_string (char *str,int str_len);

NODE * yk_find_data_from_hash_table(HASH_TABLE * hashTb,type key,int key_len);
STATUS yk_insert_data_into_hash_table(HASH_TABLE * hashTb,type key,int key_len);
void   yk_output_result(HASH_TABLE * hashTb);
void yk_print_str(char * str,int str_len);
void yk_cpy_str(char *dst,char *src,int str_len);
int yk_strcmp(char * str1,char *str2,int len1,int len2);


#endif /* YK_HASH_H_ */
