#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) \
   ({ typeof (a) _a = (a); \
        typeof (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef int element;

typedef struct TreeNode { 
    element item;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *create_node(TreeNode *left, element item, TreeNode *right) {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->item = item;
        new_node->left = left;
        new_node->right = right;
        return new_node;
    }
}

int get_node_count(TreeNode *bt) {
    int count=0; 
    if( bt != NULL ) { 
        count = 1 + get_node_count(bt->left) + get_node_count(bt->right);
    } 
    return count;
}

int get_height(TreeNode *bt) {
    int height=0;
    if( bt != NULL ) {
        height = 1 + MAX(get_height(bt->left), get_height(bt->right));
    }
    return height;
}

void in_order(TreeNode *bt){
    if ( bt != NULL ){
        in_order(bt->left);
        printf("%d ", bt->item);
        in_order(bt->right);
    }
}

void pre_order(TreeNode *bt){
    if ( bt != NULL ){
        printf("%d ", bt->item);
        pre_order(bt->left);
        pre_order(bt->right);
    }
}

void post_order(TreeNode *bt){
    if ( bt != NULL ){
        post_order(bt->left);
        post_order(bt->right);
        printf("%d ", bt->item);
    }
}

TreeNode *search(TreeNode *bt, int key) { 
    while(bt != NULL){
        if( key == bt->item ) {
            return bt;
        } else if ( key < bt->item ) {
            bt = bt->left;
        } else {
            bt = bt->right;
        }
    }
    return NULL;
} 

TreeNode *search_recur(TreeNode *bt, int key) { 
    if ( bt == NULL ) {
        return NULL;
    }
    if ( key == bt->item ) {
        return bt;
    } else if ( key < bt->item ) {
        return search_recur(bt->left, key);
    } else {
        return search_recur(bt->right, key);
    }
}

void insert_node(TreeNode **root, int key) { 
    TreeNode *p, *t; 
    TreeNode *n;  
    t = *root; 
    p = NULL; 
 
    while (t != NULL){ 
        if( key == t->item ) {
            return;
        } 
        p = t;
        if( key < t->item ) {
            t = p->left;
        } else {
            t = p->right;
        }
    }

    n = (TreeNode *) malloc(sizeof(TreeNode)); 
    if( n == NULL ) {
        perror("malloc error!\n");
    } else {
        n->item = key; 
        n->left = n->right = NULL;
    } 
 
    if( p != NULL ) {
        if( key < p->item ) { 
            p->left = n; 
        } else { 
            p->right = n;
        } 
    } else {
        *root = n;
    }
}

void delete_node(TreeNode **root, int key) {
    TreeNode*p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;

    while ( t != NULL && t->item != key ) {
        p = t;
        t = ( key < p->item ) ? p->left : p->right;
    }

    if( t == NULL ) {
        printf("keyis not in the tree");
        return;
    }

    if ( (t->left==NULL) && (t->right==NULL) ) {
        if( p != NULL ) {
            if( p->left == t ) {
                p->left = NULL;
            } else {
                p->right = NULL;
            }
        } else {
            *root = NULL;
        }
    } else if ( (t->left==NULL) || (t->right==NULL) ) {
        child = (t->left != NULL) ? t->left : t->right;
        if( p != NULL ){
            if( p->left == t ) {
                p->left = child;
            } else {
                p->right = child;
            }
        } else {
            *root = NULL;
        }
    } else {
        succ_p = t; 
        succ = t->right; 
        while( succ->left != NULL ){
            succ_p = succ; 
            succ = succ->left;
        }

        if( succ_p->left == succ ) {
            succ_p->left = succ->right;
        } else { 
            succ_p->right = succ->right;
        }
        t->item = succ->item; 
        t = succ;
    }
    free(t);
}

int main(void) {
    TreeNode *root1 = NULL;
    insert_node(&root1, 6);
    insert_node(&root1, 2);
    insert_node(&root1, 1);
    insert_node(&root1, 4);
    insert_node(&root1, 3);
    insert_node(&root1, 5);
    insert_node(&root1, 7);
    insert_node(&root1, 8);
    insert_node(&root1, 9);
    printf("pre_order : ");
    pre_order(root1);
    printf("\n");
    printf("in_order : ");
    in_order(root1);
    printf("\n");
    printf("post_order : ");
    post_order(root1);
    printf("\n");
    printf("node count : %d\n", get_node_count(root1));
    printf("tree height : %d\n", get_height(root1));

    TreeNode *root2 = NULL;
    insert_node(&root2, 41);
    insert_node(&root2, 20);
    insert_node(&root2, 72);
    insert_node(&root2, 11);
    insert_node(&root2, 29);
    insert_node(&root2, 32);
    insert_node(&root2, 50);
    insert_node(&root2, 91);
    insert_node(&root2, 45);
    insert_node(&root2, 51);
    insert_node(&root2, 90);
    insert_node(&root2, 99);
    printf("pre_order: ");
    pre_order(root2);
    printf("\n");
    printf("node count : %d\n", get_node_count(root2));
    printf("tree height : %d\n", get_height(root2));
    delete_node(&root2, 50);
    delete_node(&root2, 32);
    delete_node(&root2, 11);
    printf("pre_order: ");
    pre_order(root2);
    printf("\n");
    printf("node count : %d\n", get_node_count(root2));
    printf("tree height : %d\n", get_height(root2));
    return 0;
}