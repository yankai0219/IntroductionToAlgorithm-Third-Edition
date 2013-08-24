
/*
* CopyRight By Yankai
* Data:2013/05/11
*/

#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


extern int backet_len ;
extern int hash_call_count ;
extern struct yk_hash_counter_entry *hlist;

#define BLOCK_LEN       1024

struct yk_hash_key {
        unsigned int key;
        struct yk_hash_key *next;
};

struct yk_hash_counter_entry {
        unsigned int hit_count;
        unsigned int entry_count;
        struct yk_hash_key *keys;
};


struct yk_hash_key* find_data_from_hash(struct yk_hash_counter_entry * hlist,unsigned int key);

void yk_insert_hash_entry(unsigned int key, struct yk_hash_counter_entry *hlist);

void hashtest_init();
void hashtest_clean();
void show_hashtest_result();

#endif
