
/*
* Modified by Yankai
* Data: 2013/05/11
*/


#include "rbtree.h"

void 
rbtree_right_rotate(rbtree_node_t ** root,rbtree_node_t * sentinel,rbtree_node_t *node)
{
    rbtree_node_t * temp;
     temp = node->left;

     node->left = temp->right;/*case 1*/
    if(temp->right != sentinel){
          temp->right->parent = node;
     }

     temp->parent = node->parent; /*case 2*/
     if(*root == node){
        *root = temp;
     }else if(node == node->parent->left){
        node->parent->left = temp;
     }else{
         node->parent->right = temp;
     }

     node->parent = temp;
     temp->right = node;
}
void 
rbtree_left_rotate(rbtree_node_t ** root,rbtree_node_t * sentinel,rbtree_node_t *node)
{
    rbtree_node_t * temp;
     temp = node->right;

     node->right = temp->left;/*case 1*/
    if(temp->left != sentinel){
          temp->left->parent = node;
     }

     temp->parent = node->parent; /*case 2*/
     if(*root == node){
        *root = temp;
     }else if(node == node->parent->left){
        node->parent->left = temp;
     }else{
         node->parent->right = temp;
     }

     node->parent = temp;
     temp->left= node;
}
void 
insert_value(rbtree_node_t * temp,rbtree_node_t * sentinel,rbtree_node_t * node) /*从结点temp开始插入node结点*/
{

    rbtree_node_t ** p ;

     for(;/*void*/;){
        if(node->key > temp->key)
               p = &temp->right;
          else if(node->key < temp->key)
               p = &temp->left;
          else{
            printf("node is equal key\n");
          }
          if(*p == sentinel)
               break;
          temp = *p;
     }
     *p = node;
     node->left = sentinel;
     node->right = sentinel;
     node->parent = temp;
     node_red(node);
}

int 
rbtree_init(rbtree_t ** rbtree,insert_node_to_tree_pt insert)
{
     rbtree_t * new_rbtree = (rbtree_t*)malloc(sizeof(rbtree_t));
     if(NULL == new_rbtree)
          return -1;
  //   memset(new_rbtree,0,sizeof(rbtree_t));
     *rbtree = new_rbtree;

     new_rbtree->root = new_rbtree->sentinel;
     new_rbtree->insert = insert;
     return 0;

}

void 
rbtree_insert_node(rbtree_t * rbtree,rbtree_node_t * node)
{
    rbtree_node_t ** root = &rbtree->root;
     rbtree_node_t * temp;
     if(*root == rbtree->sentinel){ /*empty tree*/
        *root = node;
        node->parent = rbtree->sentinel;
        node->left   = rbtree->sentinel;
        node->right  = rbtree->sentinel;
        return ;/*essential*/
     }
     rbtree->insert(rbtree->root,rbtree->sentinel,node);/*comman binary search tree insert */
     /*modify the binary search tree after insert*/

     while((node != *root) && (node_is_red(node->parent))){
        if(node->parent == node->parent->parent->left){
               temp = node->parent->parent->right;

               if(node_is_red(temp)){/*case 1*/
                node_black(node->parent);
                    node_black(temp);
                    node_red(node->parent->parent);
                    node = node->parent->parent;
               }else{

                if(node == node->parent->right){/*case 2*/
                    node = node->parent;
                         rbtree_left_rotate( root,rbtree->sentinel, node);
                    }
                    /*case 3*/
                    node_black(node->parent);
                    node_red(node->parent->parent);
                    rbtree_right_rotate(root,rbtree->sentinel, node->parent->parent);

               }

          }/*parent of node is the left of parent of parent of node */
          else{
               temp = node->parent->parent->left;
               if(node_is_red(temp)){/*case 1*/
                   node_black(node->parent);
                    node_black(temp);
                    node_red(node->parent->parent);
                    node = node->parent->parent;
               }else{

                    if(node == node->parent->left){/*case 2*/
                         node = node->parent;
                         rbtree_right_rotate( root,rbtree->sentinel, node);
                    }
                    /*case 3*/
                    node_black(node->parent);
                    node_red(node->parent->parent);
                    rbtree_left_rotate(root,rbtree->sentinel, node->parent->parent);/*left rotate must be temp->parent or node->parent->parent*/

               }

          }/*parent of node is the right of parent of parent of node */

     }/*while*/
    node_black(*root);
}

rbtree_node_t * 
rbtree_create_node(int key)
{
	rbtree_node_t * newnode = NULL;
	newnode = (rbtree_node_t *)malloc(sizeof(rbtree_node_t));
	if(NULL == newnode)
		return NULL;
	memset(newnode,0,sizeof(rbtree_node_t));
	newnode->key = key;

	return newnode;
}

void 
rbtree_traverse(rbtree_node_t *node,rbtree_node_t * sentinel)
{
	if(node == sentinel)
		return ;
	rbtree_traverse(node->left,sentinel);
	printf("key : %d color :%d\n",node->key,node->color);
	rbtree_traverse(node->right,sentinel);
}

rbtree_node_t * 
rbtree_min_node(rbtree_node_t * node,rbtree_node_t *sentinel)
{
	rbtree_node_t *temp = node;
    for(;temp->left != sentinel;)
    	temp = temp->left;
    return temp;
}

void 
rbtree_delete(rbtree_t *rbtree,rbtree_node_t *node)
{
	/*
	 * description : subst :the real deleted node
	 *               temp  : the node which will replace subst after subst is deleted;
	 * */
	rbtree_node_t * temp,*subst;


	//step 1: find the location of  subst and temp .
    if(node->left == rbtree->sentinel){
    	subst = node;
    	temp = subst->right;
    }else if(node->right == rbtree->sentinel){
    	subst = node;
    	temp = subst->left;
    }else{
    	subst = rbtree_min_node(node->right,rbtree->sentinel);
    	temp = subst->right; /*it is different from nginx rbtree,because I think there is no left child for subst,so temp is sentinel or temp is subst->right child*/
    }
    //step 2:replace node with subst

    if(temp != rbtree->sentinel)
    	temp->parent = subst->parent;

    if(subst->parent == NULL) /*must add the correction of subst is root node */
    	rbtree->root = temp;
    else if(subst == subst->parent->right)
    	subst->parent->right = temp;
    else
    	subst->parent->left = temp;
    //step 3: change the value of node with the content of subst
    if(subst != node){
    	node->key = subst->key;
    }
   free(subst);
}


void 
rbtree_fixup_delete(rbtree_t *rbtree,rbtree_node_t *node)
{
	/*
	 * description : subst :the real deleted node
	 *               temp  : the node which will replace subst after subst is deleted;
	 * */
	rbtree_node_t * temp,*subst;
	rbtree_node_t * w;
	int red = 0;
	//step 1: find the location of  subst and temp .
    if(node->left == rbtree->sentinel){
    	subst = node;
    	temp = subst->right;
    }else if(node->right == rbtree->sentinel){
    	subst = node;
    	temp = subst->left;
    }else{
    	subst = rbtree_min_node(node->right,rbtree->sentinel);
    	temp = subst->right; /*it is different from nginx rbtree,because I think there is no left child for subst,so temp is sentinel or temp is subst->right child*/
    }
    //step 2:replace node with subst

  //  if(temp != rbtree->sentinel)/*for rbtree delete*/
    	temp->parent = subst->parent;

    if(subst->parent == rbtree->sentinel) /*must add the correction of subst is root node */
    	rbtree->root = temp;
    else if(subst == subst->parent->right)
    	subst->parent->right = temp;
    else
    	subst->parent->left = temp;
    //step 3: change the value of node with the content of subst
    if(subst != node){
    	node->key = subst->key;
    }
    red = node_is_red(subst);
    if(1 == red){
    	printf("delete red node\n");
    	return ;
    }

    while((temp != rbtree->root) && (node_is_black(temp)) ){
    	if(temp == temp->parent->left){/*temp is left node*/
    		w = temp->parent->right;
    		if(node_is_red(w)){/*case1: the brother node of(temp) is red;through next steps,we change the case from 1 to 2 or 3 or 4*/
    			/*it is essential to change color*/
    			node_black(w);
    			node_red(temp->parent);
    			rbtree_left_rotate(&rbtree->root,rbtree->sentinel,temp->parent);/*rotate temp->parent*/
    			w = temp->parent->right;
    		}
    		if(node_is_black(w->right) && node_is_black(w->left)){/*case 2*/
    			node_red(w);
    			temp = temp->parent;

    		}else {

    			if(node_is_black(w->right)){/*case 3 : the far nephew of temp node is black.through next steps,we change the case from 3 to 4*/
    				node_black(w->left);
    			    node_red(temp->parent);
    			    rbtree_right_rotate(&rbtree->root,rbtree->sentinel,w);
    			    w = temp->parent->right;
    		    }
				/*case 4 :the far nephew of temp node is red*/
				copy_node_color(w,temp->parent);
				node_black(temp->parent);
				node_black(w->right);
				rbtree_left_rotate(&rbtree->root,rbtree->sentinel,temp->parent);/*rotate temp->parent*/
				temp = rbtree->root;
    		}
    	}else {/*temp is right node*/
    		w = temp->parent->left;
    		if(node_is_red(w)){/*case1: the brother node of(temp) is red;through next steps,we change the case from 1 to 2 or 3 or 4*/
    			/*it is essential to change color*/
    			node_black(w);
    			node_red(temp->parent);
    			rbtree_right_rotate(&rbtree->root,rbtree->sentinel,temp->parent);/*rotate temp->parent*/
    		    w = temp->parent->left;
    		}
    		if(node_is_black(w->right) && node_is_black(w->left)){/*case 2*/
    			node_red(w);
    		    temp = temp->parent;
    		 }else  {
    			 if(node_is_black(w->left)){/*case 3 : the far nephew of temp node is black.through next steps,we change the case from 3 to 4*/
    				node_black(w->right);
					node_red(temp->parent);
					rbtree_left_rotate(&rbtree->root,rbtree->sentinel,w);
					w = temp->parent->left;
    		    }
				 /*case 4 :the far nephew of temp node is red*/
				 copy_node_color(w,temp->parent);
				 node_black(temp->parent);
				 node_black(w->left);
				 rbtree_right_rotate(&rbtree->root,rbtree->sentinel,temp->parent);/*rotate temp->parent*/
				 temp = rbtree->root;
    		 }
    	}
    }/*while*/
    node_black(temp);

}


rbtree_node_t * 
rbtree_search_key(rbtree_t * rbtree,int key)
{
	rbtree_node_t * node = rbtree->root;
	for(;;){
		if(node == rbtree->sentinel)
			break;
		if(node->key > key)
			node = node->left;
		else if(node->key < key)
			node = node->right;
		else{
			break;
		}
	}
	return node;

}

