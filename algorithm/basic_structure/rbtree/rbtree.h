
/*
* rbtree.h
*
*  Created on: Dec 4, 2012
*  Author: YanKai
*  Modified Data: 2013/05/11
*
 */

#ifndef RBTREE_H_
#define RBTREE_H_


//红黑树插入代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
typedef struct rbtree_node_s rbtree_node_t;
typedef struct rbtree_s rbtree_t;
typedef  void (*insert_node_to_tree_pt)(rbtree_node_t * temp,rbtree_node_t * sentinel,rbtree_node_t * node);

struct rbtree_node_s {
     rbtree_node_t   *left;
     rbtree_node_t   *right;
     rbtree_node_t   *parent;
     int             key;
     int             color;/*color = 1,red;color = 0,black*/
};
struct rbtree_s{
    rbtree_node_t            * root;
     rbtree_node_t           * sentinel;
     insert_node_to_tree_pt  insert;

};

#define node_is_black(node) ( (node)->color == 0)
#define node_is_red(node)   ( (node)->color == 1)
#define node_black(node)    ( (node)->color = 0)
#define node_red(node)      ( (node)->color = 1)
#define copy_node_color(dst,src) ( (dst)->color = (src)->color )
int rbtree_init(rbtree_t ** rbtree,insert_node_to_tree_pt insert);
void insert_value(rbtree_node_t * temp,rbtree_node_t * sentinel,rbtree_node_t * node); /*从结点temp开始插入node结点*/
 void rbtree_right_rotate(rbtree_node_t ** root,rbtree_node_t * sentinel,rbtree_node_t *node);
 void rbtree_left_rotate(rbtree_node_t ** root,rbtree_node_t * sentinel,rbtree_node_t *node);
void rbtree_insert_node(rbtree_t * rbtree,rbtree_node_t * node);
rbtree_node_t * rbtree_create_node(int key);
void rbtree_traverse(rbtree_node_t *node,rbtree_node_t * sentinel);
rbtree_node_t * rbtree_min_node(rbtree_node_t * node,rbtree_node_t *sentinel);
/*
 * there is node whose key is key ,return its address
 * there is no node ,return sentinel
 * */
rbtree_node_t * rbtree_search_key(rbtree_t * rbtree,int key);

void rbtree_delete(rbtree_t *rbtree,rbtree_node_t *node);/*binary search tree delete*/
void rbtree_fixup_delete(rbtree_t *rbtree,rbtree_node_t *node);/*red-black tree delete*/





#endif /* RBTREE_H_ */
