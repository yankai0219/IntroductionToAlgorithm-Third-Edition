
/*
* CopyRight by Yankai
* Data:2013/05/11
*/

#include "hash.h"



struct yk_hash_key* 
find_data_from_hash(struct yk_hash_counter_entry * hlist,unsigned int key)
{

        unsigned int hash_value;
        struct yk_hash_key * pNode;

        if(hlist == NULL)
                return NULL;
        hash_value = key % BLOCK_LEN;
        if( hlist[hash_value].keys == NULL){
                printf("NO CHAIN\n");
                return NULL;
        }

        for(pNode = hlist[hash_value].keys;pNode;pNode = pNode->next){
                if(key == pNode->key)
                        return pNode;
        }
        return NULL;
}

void 
yk_insert_hash_entry(unsigned int key, struct yk_hash_counter_entry *hlist)
{
        unsigned int hash_value = key % backet_len;
        struct yk_hash_key *p,*new_node;

        p = hlist[hash_value].keys;

        if(NULL == p){/*no chain*/
                p = (struct yk_hash_key *)malloc(sizeof(struct yk_hash_key));
                if (NULL == p){
                                        perror("malloc in insert_hash_entry");
                                        return;
                }
                p->key = key;
                p->next = NULL;
                hlist[hash_value].keys = p;
                hlist[hash_value].entry_count++;
                return;
        }
        if( (find_data_from_hash(hlist,key)) ){
                printf("data has existed in hash table\n");
                hlist[hash_value].hit_count++;
                return;
        }
        for(;p->next;)
                p = p->next;

        new_node = (struct yk_hash_key *)malloc(sizeof(struct yk_hash_key));
        if (new_node == NULL){
                perror("malloc in insert_hash_entry");
                return;
        }
        new_node->key = key;
        new_node->next = NULL;
        p->next = new_node;
        hlist[hash_value].entry_count++;
        hlist[hash_value].hit_count++;
}

void 
hashtest_init()
{
        int i;

        hash_call_count = 0;
        hlist = (struct yk_hash_counter_entry *) malloc (sizeof(struct yk_hash_counter_entry) *  backet_len);
        if (NULL == hlist)
        {
                perror("malloc in hashtest_init");
                return;
        }
        for (i = 0; i < backet_len; i++)
        {
                hlist[i].hit_count = 0;
                hlist[i].entry_count = 0;
                hlist[i].keys = NULL;
        }
}



void
hashtest_clean()
{
        int i;
        struct yk_hash_key *pentry, *p;

        if (NULL == hlist)
                return;

        for (i = 0; i < backet_len; ++i)
        {
                pentry = hlist[i].keys;
                while(pentry)
                {
                        p = pentry->next;

                        free(pentry);
                        pentry = p;
                }
        }
        free(hlist);
}

void 
show_hashtest_result()
{
        int i, backet = 0, max_link = 0, sum = 0;
        int conflict_count = 0, hit_count = 0;
        double avg_link, backet_usage;

        for(i = 0; i < backet_len; i++)
        {
                if (hlist[i].hit_count > 0)
                {
                        backet++;
                        sum += hlist[i].entry_count;
                        if (hlist[i].entry_count > max_link)
                        {
                                max_link = hlist[i].entry_count;
                        }
                        if (hlist[i].entry_count > 1)
                        {
                                conflict_count++;
                        }
                        hit_count += hlist[i].hit_count;
                }
        }

        backet_usage = backet/1.0/backet_len * 100;;
        avg_link = sum/1.0/backet;

        printf("backet_len = %d\n", backet_len);
        printf("hash_call_count = %d\n", hash_call_count);
        printf("hit_count = %d\n", hit_count);
        printf("conflict count = %d\n", conflict_count);
        printf("longest hash entry = %d\n", max_link);
        printf("average hash entry length = %.2f\n", avg_link);
        printf("backet usage = %.2f\n", backet_usage);
}

