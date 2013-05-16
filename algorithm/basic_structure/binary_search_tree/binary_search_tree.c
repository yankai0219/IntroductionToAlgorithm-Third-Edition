
/*
* CopyRight By YK
* Data:2013/05/10
*/


#include "common.h"
#include "binary_search_tree.h"


void replace_a_with_b(bst_node_t *a, bst_node_t *b);

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

bst_t * 
init_bst_tree()
{
    bst_node_t *sentinel;
    bst_t * bst;
    
    sentinel = (bst_node_t *)calloc(1,sizeof(bst_node_t));
    bst = (bst_t*)calloc(1,sizeof(bst_t));
    if (bst == NULL || sentinel == NULL) {
        err_exit("calloc error\n");
    }

   bst->root = sentinel;
   bst->sentinel = sentinel;
   
   return bst;
}

bst_node_t *
create_node(bst_t *bst, int value)
{
    bst_node_t * bst_node;
    
    bst_node = (bst_node_t*)calloc(1,sizeof(bst_node_t));
    if (bst_node == NULL) {
        err_exit("calloc error\n");
    }
    
    bst_node->key = value;
    bst_node->parent = bst->sentinel;
    bst_node->right  = bst->sentinel;
    bst_node->left   = bst->sentinel;
    
    return bst_node;
}
bst_node_t*
find_successor_bst_tree(bst_t *bst, int value)
{
    bst_node_t *bst_node,  *mid_node;
    
    bst_node = search_node_bst_tree(bst,value);

    if (bst_node->right != bst->sentinel) {
        return  minimum(bst,bst_node->right);
    }

    mid_node = bst_node->parent;

    while(mid_node != bst->sentinel && bst_node == mid_node->right) {
        bst_node = mid_node;
        mid_node = mid_node->parent;
    }
 
    return mid_node;
}

/*
****                Insert value into binary search tree    ************
* Two Cases:
* 1) Emptye Tree
* 2) Find the last node which is the parent of InsertNode
*/
int    
insert_value_bst_tree(bst_t *bst, int value)
{
    bst_node_t *bst_node,*tmp_node,*last_node;

    bst_node = create_node(bst, value);
    
    if (bst->root == bst->sentinel) {/*empty tree*/
        bst->root = bst_node;
        return 0;
    }

    tmp_node = bst->root;
    
    while (tmp_node != bst->sentinel) {/*search the last element which would be inserted*/
        last_node = tmp_node;
         
        if ( tmp_node->key > value) {
            tmp_node = tmp_node->left; 
        } else {
            tmp_node = tmp_node->right;
        }
    }

    /*insert bst_node to last_node*/
    if (last_node->key < value) {
        last_node->right = bst_node; 
    } else {
        last_node->left = bst_node;
    }   

    bst_node->parent = last_node;/*essential step*/

    return 0;   

}

int 
inorder_traverse(bst_node_t *bst_node,bst_t * bst)
{
    
    if(bst_node != bst->sentinel) {
        inorder_traverse(bst_node->left,bst);
        printf("key:%d\n",bst_node->key);
        inorder_traverse(bst_node->right,bst);
    }
    return 0;
}

bst_node_t * 
search_node_bst_tree(bst_t *bst, int value)
{
    bst_node_t *tmp_node;

    tmp_node = bst->root;

    while(tmp_node != bst->sentinel) {
        if(tmp_node->key == value){
            break;
        }else if(tmp_node->key > value){
            tmp_node = tmp_node->left;
        }else {
            tmp_node = tmp_node->right;
        }
    }
    
    if(tmp_node == bst->sentinel) {
        tmp_node = NULL;
    }
    
    return tmp_node;
}

/*
*****             Delete value from Binary Search Tree       ***********
*  About Deletion:
*  Three Case:
*  1) Delete Node contains NO child.
*  2) Delete Node contains ONLY ONE child.
*  3) Delete Node contains TWO child
*      When the deletion operation contains two nodes, the FIRST thing is 
*      to find the successor y. 
*/

bst_node_t * 
minimum(bst_t *bst, bst_node_t *node)
{
    while(node->left != bst->sentinel) {
        node = node->left ;
    }
    
    return node;
}

int 
delete_elem_bst_tree(bst_t *bst, int value)
{
    bst_node_t * del_node;
    bst_node_t * mid_node;
 
    if(bst->root == bst->sentinel) {
        printf("Empty Tree\n");
        return 0;
    }
 
    del_node = search_node_bst_tree(bst, value);
    
    if (del_node == NULL){
        printf("NO node %d\n",value);
        return 0;
    }



    if (del_node->left == bst->sentinel) {/*the delete node contains one nodes*/
        
        /*del_node is root,it should be operate*/
        if(del_node->parent == bst->sentinel) {
            bst->root = del_node->right;
        }
       
        replace_a_with_b(del_node,del_node->right);
        
    } else if (del_node->right == bst->sentinel) {
        
        /*del_node is root,it should be operate*/
        if(del_node->parent == bst->sentinel) {
            bst->root = del_node->left;
        }

        replace_a_with_b(del_node,del_node->left);
    
    } else {/*the delete node contains two nodes*/
      
        mid_node = minimum(bst, del_node->right);
/*del_node is root*/
        if(del_node->parent == bst->sentinel) {
            mid_node->left = bst->root->left;
            bst->root = mid_node;
            bst->root->left->parent = bst->root;            
        }
/*the mid_node is the right child of the delete node*/
        if (mid_node == del_node->right ) { 

            replace_a_with_b(del_node, mid_node);
            return 0;
        } 
       
/*the middle node is NOT the right child of the delete node*/
        replace_a_with_b(mid_node, mid_node->right);        /*replace the mid_node with the mid_node->right node */  
        replace_a_with_b(del_node,mid_node);
        
    }
 
    free(del_node);
 
    return 0;
}

void replace_a_with_b(bst_node_t *a, bst_node_t *b)
{
    
   if(a == a->parent->left) {/*replace the del_node with the mid_node */
        a->parent->left = b;
   } else {
        a->parent->right = b;
   }
   b->parent = a->parent;
}

void 
bst_free(bst_t *bst, bst_node_t *node)
{
    if(bst->root == bst->sentinel) {
        free(bst);
        return ;
    }

    if (node == bst->sentinel) {
        return ;
    }
    bst_free(bst, node->left);
    bst_free(bst, node->right);
    printf_debug("free key:%d\n",node->key);
    free(node);

    return ;
}
