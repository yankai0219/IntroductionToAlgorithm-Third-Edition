/*
 * hashtest.c
 *
 *  Created on: Nov 12, 2012
 *      Author: root
 */
#include "str_hash_func.h"
#include "hash.h"
 
 int backet_len = 1024;
 int hash_call_count = 0;
 struct yk_hash_counter_entry *hlist = NULL;


int main(int argc, char *argv[])
{
	int fd = -1, rwsize = 0;
	 char buf[BLOCK_LEN] = {0};
	unsigned int key;
//	char * file_path = "eclipse-jee-juno-SR1-linux-gtk.tar.gz";
        
        if(argc != 2) {
            printf("input parameter ERROR\n");
            return 0;
        }       
 
	if (-1 == (fd = open(argv[1], O_RDONLY)))
	{
		perror("open source file ,please modify file_path");
		return errno;
	}


	hashtest_init();

	while (rwsize = (int)read(fd, buf, BLOCK_LEN))
	{

		key = yk_simple_hash(buf,rwsize);
	//	printf("data:%d\n",key);
		yk_insert_hash_entry(key, hlist);
		hash_call_count++;
		memset(buf, 0, BLOCK_LEN);
	}
	close(fd);

	show_hashtest_result();
	hashtest_clean();
	return 0;
}
