/*
* CopyRight By YK
* Data:2013/05/10
*/

#include "binary_search_tree.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int          i, len;
    bst_t        *bst;
//    bst_node_t  *successor;

    int array[] = {23,4,34,2,134,6};
    
    len = sizeof(array)/sizeof(int);

    bst = init_bst_tree();
    for (i = 0; i < len; i++) {
        insert_value_bst_tree(bst, array[i]);
    }    
    printf("traverse\n");
    inorder_traverse(bst->root,bst);
/*
    printf("Find SUCCESSOR 23\n");
    successor = find_successor_bst_tree(bst, 23);
    printf("23 successor(should be 34) :%d\n",successor->key);
    
    printf("Find SUCCESSOR 2\n");
    successor = find_successor_bst_tree(bst, 2);
    printf("23 successor(should be 4) :%d\n",successor->key);

    printf("Find SUCCESSOR 6\n");
    successor = find_successor_bst_tree(bst, 6);
    printf("23 successor(should be 23) :%d\n",successor->key);
    printf("after DELETE 34\n");
    delete_elem_bst_tree(bst,34);
    inorder_traverse(bst->root,bst);
    printf("after DELETE 23\n");
    delete_elem_bst_tree(bst,23);
    inorder_traverse(bst->root,bst);
    printf("after DELETE 134\n");
    delete_elem_bst_tree(bst,134);
    inorder_traverse(bst->root,bst);
    printf("after DELETE 2\n");
    delete_elem_bst_tree(bst,2);
    inorder_traverse(bst->root,bst);
    printf("after DELETE 4\n");
    delete_elem_bst_tree(bst,4);
    inorder_traverse(bst->root,bst);
    printf("after DELETE 4\n");
    delete_elem_bst_tree(bst,4);
    inorder_traverse(bst->root,bst);
  */  
    bst_free(bst,bst->root);
    return 0;
}
