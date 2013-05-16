/*
 * rbtree_main.c
 *
 *  Created on: Dec 4, 2012
 *      Author: root
 */

#include "rbtree.h"

int main(void)
{
    rbtree_t *rbtree;
    rbtree_node_t *node = NULL,*sentinel = NULL;
    rbtree_node_t *del_node = NULL;
    int key_array[] = {12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17};

    int i;
    /*initial*/
    sentinel = (rbtree_node_t*)malloc(sizeof(rbtree_node_t));
    rbtree  = (rbtree_t *)malloc(sizeof(rbtree_t));
    if(NULL == sentinel || NULL ==rbtree)
    	return -1;
    node_black(sentinel);
    rbtree->root = sentinel;
    rbtree->sentinel = sentinel;
    rbtree->insert = insert_value;
    /*initial*/
    for(i = 0; i < sizeof(key_array)/sizeof(int); i++){
    	node = rbtree_create_node(key_array[i]);
    	rbtree_insert_node(  rbtree, node);
    }
    rbtree_traverse(rbtree->root,rbtree->sentinel);
    for(i = 0; i < sizeof(key_array)/sizeof(int); i++){
    	del_node =  rbtree_search_key( rbtree,key_array[i]);
    	if(del_node == rbtree->sentinel){
    		printf("there is no key\n");
    		return -1;
    	}
    //	rbtree_delete(rbtree,del_node);/*binary search tree delete*/
    	rbtree_fixup_delete(rbtree,del_node);
    	printf("after delete node %d\n",key_array[i]);
 //   	rbtree_traverse(rbtree->root,rbtree->sentinel);
    }

    return 0;
}
