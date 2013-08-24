/*
 * yk_hash_main.c
 *
 *  Created on: Nov 13, 2012
 *      Author: root
 */


#include"hash.h"
#include<fcntl.h>
#include<unistd.h>
#define SIZE_PER_BUF 6
int main()
{
	HASH_TABLE * hashTb = NULL;
	int fd = -1,rdsize;
	char buf[SIZE_PER_BUF]={0};
	char * file_path = "testForTop10.txt";
	int call_count =0;
	hashTb = yk_hash_table_init();


	if(-1 == (fd = open(file_path,O_RDONLY))){
		printf("OPEN ERROR\n");
		return -1;
	}
	printf("open file succeed\n");
	while(rdsize = (int)read(fd,buf,SIZE_PER_BUF)){
		 yk_insert_data_into_hash_table( hashTb,buf,rdsize);
		 call_count++;
	}


	printf("call count is %d\n",call_count);
	yk_output_result(hashTb);
	return 0;

}
