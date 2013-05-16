/*
 * yk_hash.c
 *
 *  Created on: Nov 13, 2012
 *      Author: root
 */


#include"hash.h"

/*for loop :hash = 31* hash + *p  */
unsigned int 
yk_simple_hash_string(char * str,int str_len)
{
	unsigned int hash;
	unsigned char * p;
	int i;
	for(i = 0, hash = 0,p = (unsigned char *)str; i < str_len && p; i++,p++)
		hash = 31 * hash + *p;

	return (hash & 0x7FFFFFFF);
}

HASH_TABLE* 
yk_hash_table_init()
{
	HASH_TABLE* hashTB = NULL;
	hashTB = (HASH_TABLE *)malloc(sizeof(HASH_TABLE)*BUCKET_LEN);
	if(NULL == hashTB){
		printf("create HASH TABLE error\n");
		return NULL;
	}
	memset(hashTB,0,sizeof(HASH_TABLE)*BUCKET_LEN);
	return hashTB;
}


NODE * 
yk_find_data_from_hash_table(HASH_TABLE * hashTb,type key,int key_len)
{
	unsigned int hash_value;
	NODE * pNode;
	hash_value = yk_simple_hash_string(key,key_len)%BUCKET_LEN;
	if(NULL == hashTb ){
		printf("NO CHAIN when find data\n");
		return NULL;
	}

	pNode = hashTb[hash_value].keys_chain;
	for(;pNode;){
		if(yk_strcmp(key,pNode->key,key_len,pNode->key_len)  == 0){
			pNode->occur_count++;
			return pNode;
		}

		pNode = pNode->next;
	}
	return NULL;
}


STATUS 
yk_insert_data_into_hash_table(HASH_TABLE * hashTb,type key,int key_len)
{
	if(NULL == hashTb ){
		printf("NO CHAIN when find data\n");
		return FALSE;
	}
	unsigned int hash_value;
	NODE * pNode,*pNewNode;
	hash_value = yk_simple_hash_string(key,key_len) % BUCKET_LEN;
	printf("hash value is %d\t key is ",hash_value);
	yk_print_str(key,key_len);


	hashTb[hash_value].hit_count++;
	pNode = hashTb[hash_value].keys_chain;
	/*no chain,so insert data into this chain*/
	if(NULL == pNode){

		if( NULL == (pNewNode = (NODE*)malloc(sizeof(NODE))) ){
			printf("allocate NODE error");
			return FALSE;
		}

		if(NULL == (pNewNode->key = (char*)malloc(key_len * sizeof(char)))){
			printf("allocate key");
			return FALSE;
		}
		/*pNewNode->key = yk_strdup(key);*/
		yk_cpy_str(pNewNode->key,key,key_len);
		pNewNode->key_len = key_len;
		pNewNode->next = NULL;
		pNewNode->occur_count = 1;
		hashTb[hash_value].keys_chain = pNewNode;

	    return TRUE;
	}
	/*data has exited in hash table */
	if( NULL != (yk_find_data_from_hash_table(hashTb, key,key_len)) )
		return FALSE;
	/*insert data into end of chain */
	for(;pNode->next;)
		pNode = pNode->next;

	if( NULL == (pNewNode = (NODE*)malloc(sizeof(NODE))) ){
				printf("allocate NODE error");
				return FALSE;
	}
	if(NULL == (pNewNode->key = (char*)malloc(key_len * sizeof(char)))){
			printf("allocate key");
			return FALSE;
	}
	yk_cpy_str(pNewNode->key,key,key_len);
	pNewNode->key_len = key_len;
	pNewNode->next = NULL;
	pNewNode->occur_count = 1;
	pNode->next = pNewNode;
	return TRUE;

}

void 
yk_cpy_str(char *dst,char *src,int str_len)
{
	int i;
	for(i = 0; i < str_len; i++){
		*(dst + i) = *( src + i);
	}
}

void   
yk_output_result(HASH_TABLE * hashTb)
{
	int i;
	NODE * pNode;
	for(i = 0; i < BUCKET_LEN;i++){
		printf("\nBUCKET:@@@ %d @@@ \nhit_count is %d\n",i,hashTb[i].hit_count);
		for(pNode = hashTb[i].keys_chain;pNode;pNode = pNode->next){
			printf("\tBUCKET:%d key_occur time is %d\n",i,pNode->occur_count);
			printf("\tBUCKET:%d key is \n",i);
			yk_print_str(pNode->key,pNode->key_len);
		}

	}
}

void 
yk_print_str(char * str,int str_len)
{
	int i = 0;
	for(;i < str_len;i++)
		printf("%c",*(str+i));
	printf("\n");
}

/*
 * return value:
 * str1 > str2:1
 * str1 == str2 :0
 * str1 < str2:-1
 * */
int 
yk_strcmp(char * str1,char *str2,int len1,int len2)
{
	int i = 0;
	for(i = 0; i < ((len1<len2)?len1:len2); i++){
		if(*(str1 + i) > *(str2 + i))
			return 1;
		else if(*(str1 + i) == *(str2 + i))
			continue;
		else
			return -1;
	}
	if(len1 < len2)
		return  -1;
	else if(len1 == len2)
		return 0;
	else
		return 1;
}
