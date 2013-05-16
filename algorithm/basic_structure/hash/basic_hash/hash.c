/*
 * yk_hash.c
 *
 *  Created on: Nov 12, 2012
 *      Author: Yankai
 *  Modified Data: 2013/05/11 
*/
#include "hash.h"

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

hash_table_t *
hash_table_init(int slot_num)
{ 
    hash_table_t *hash_tb= NULL;

    hash_tb = (hash_table_t *)calloc(1,sizeof(hash_table_t));
    if(hash_tb == NULL) {
        err_exit("calloc error\n");
    }

    hash_tb->hash_tb = (hash_elem_t **)calloc(slot_num, sizeof(hash_elem_t*));
    if(hash_tb->hash_tb == NULL) {
        err_exit("calloc error\n");
    }

    hash_tb->hash_slot_number = slot_num;

    return hash_tb;
}

/*HashInt is hash function*/
unsigned long 
HashInt(hash_table_t *ht, int data)
{
	return data % ht->hash_slot_number;
}

hash_elem_t* 
find_data_from_hash(hash_table_t * hash_table,int data)
{

    unsigned long   key;
    hash_elem_t    *pNode;
        
    if(hash_table->hash_tb == NULL){
       printf("EMPTY hash table\n");
       return NULL;
    }

    key = HashInt(hash_table,data);
    
    if((pNode = hash_table->hash_tb[key]) == NULL){
        printf("NO CHAIN\n");
        return NULL;
    }
 
    for(; pNode; pNode = pNode->next){
        
        if(data == pNode->key.key){
            return pNode;
        }
    }
   
    printf("NO Data :%d\n",data);
    return NULL;
}

STATUS 
insert_data_into_hash(hash_table_t * hash_table, int data)
{
    unsigned long key;

    hash_elem_t * pNode,*pNewNode;

    if(hash_table == NULL){
        err_exit("hash_table_t is NULL\n");
    }	

    key = HashInt(hash_table,data);

/*the slot of Hash key of data is NULL */
    if((pNode = hash_table->hash_tb[key]) == NULL){
        if((pNewNode = (hash_elem_t*)calloc(1,sizeof(hash_elem_t))) == NULL){
            err_exit("malloc error\n");
        }
        
        pNewNode->key.key = data;
        pNewNode->next = NULL;

	hash_table->hash_tb[key] = pNewNode;
        printf("insert succeed \n");
        return TRUE;
    }/*if*/

/*the slot of Hash key of data is NOT NULL . OPERATE COLLISION */

    if( (find_data_from_hash(hash_table,data)) ){/*if data exits in hash table,it should return FALSE*/
        printf("data %d exits in hash table\n",data);
        return FALSE;
    }

    for(; pNode->next; ) {
        pNode = pNode->next;
    }/*for*/

    if( ( pNewNode = (hash_elem_t*)calloc(1,sizeof(hash_elem_t))) == NULL){
        err_exit("calloc error\n");
    }

    pNewNode->key.key = data;
    pNewNode->next = NULL;

    pNode->next = pNewNode;/*insert data to end of chain*/
    printf("Insert Success\n");

    return TRUE;
}

STATUS 
delete_data_from_hash(hash_table_t * hash_table, int data)
{
    unsigned long key;
    hash_elem_t  *pNode,*pLocNode;

    if(hash_table == NULL){
        printf("hashtb is NULL\n");
        return FALSE;
    }

    key = HashInt(hash_table,data);

    if((pNode = hash_table->hash_tb[key]) == NULL){
        printf("when delete,NO Data:%d\n",data);
        return FALSE;
    }
	/*if data does not exit in hash table,it should return FALSE*/	
    if( (pLocNode = find_data_from_hash(hash_table,data)) ==FALSE){
        printf("when delete,NO Data:%d\n",data);
        return FALSE;
    }
   
    if(pLocNode == pNode){/*node is located head of chain*/
        pNode->next = NULL;
        free(pLocNode);
        return TRUE;
    }

    while(pNode->next != pLocNode){/*node is not located head of chain*/
        pNode = pNode->next;
    }

    pNode->next = pLocNode->next;
    free(pLocNode);
    return TRUE;
}

STATUS
output_data_in_hash(hash_table_t * hash_table){
    int          i,len;
    hash_elem_t *pNode;
    
    len = hash_table->hash_slot_number;  
 
    for(i = 0;i < len;i++){
        if(hash_table->hash_tb[i] != NULL)
            for(pNode = hash_table->hash_tb[i];pNode;pNode = pNode->next)
                printf("data in hash_table[%d] : %d\n",i,pNode->key.key);
    }/*for*/
    return TRUE;
}

void            
hash_table_free(hash_table_t *hash_tb)
{

    int           i,len;
    hash_elem_t  *pNode, *tmp;

    len = hash_tb->hash_slot_number;

    for (i = 0; i < len; i++) {
        if(hash_tb->hash_tb[i] != NULL) {
            pNode = hash_tb->hash_tb[i]; 

            while(pNode) {
                printf_debug("FREE data [%d] : %d\n",i,pNode->key.key);
                tmp = pNode->next;
                free(pNode);
                pNode = tmp;
            }
        }
    }
    free(hash_tb);
    
}
