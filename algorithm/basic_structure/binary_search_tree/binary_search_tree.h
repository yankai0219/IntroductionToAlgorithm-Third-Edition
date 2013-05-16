
/*
* CopyRight By YK
* Data:2013/05/10
*/

/***               a Question: How to Initial                *****
* When building tree data structure, it is better to build two data structure. One is tree structure, the other is node structure.
* The tree structure contains only root and sentinel elements. When tree is empty, root = sentinel;
* The node structure contains parent,left,right,key.
*
*/

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_  

#include "common.h"


#define _print_debug_ 1
#if _print_debug_
#define printf_debug(...) printf(__VA_ARGS__)
#else
#define printf_debug(...)
#endif

typedef struct binary_search_tree_s bst_t;
typedef struct binary_search_tree_node_s bst_node_t;

struct binary_search_tree_node_s {
    bst_node_t *parent;
    bst_node_t *left;
    bst_node_t *right;
    int key;
};

struct binary_search_tree_s {
   bst_node_t *root;
   bst_node_t *sentinel;
};



int         inorder_traverse(bst_node_t *bst_node, bst_t *bst);
int         insert_value_bst_tree(bst_t *bst, int value);
int         delete_elem_bst_tree(bst_t *bst, int value);
void        bst_free(bst_t *bst, bst_node_t *node);
bst_t      *init_bst_tree(void);

bst_node_t *create_node(bst_t *bst, int value);
bst_node_t *search_node_bst_tree(bst_t *bst,int value);
bst_node_t *find_successor_bst_tree(bst_t *bst, int value);
bst_node_t *minimum(bst_t *bst, bst_node_t *node);

#endif 
