#include <stdio.h>
#include <stdlib.h>

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *create_node(element item, TreeNode *left, TreeNode *right) {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if ( new_node == NULL ) {
        perror("error");
    } else {
        new_node->data = item;
        new_node->left = left;
        new_node->right = right;
        return new_node;
    }
}

void pre_order(TreeNode *T) {
    if ( T != NULL ) {
        printf("%d ", T->data);
        pre_order(T->left);
        pre_order(T->right);
    }
}

void in_order(TreeNode *T) {
    if ( T != NULL ) {
        in_order(T->left);
        printf("%d ", T->data);
        in_order(T->right);
    }
}

void post_order(TreeNode *T) {
    if ( T != NULL ) {
        post_order(T->left);
        post_order(T->right);
        printf("%d ", T->data);
    }
}

int get_height(TreeNode *T) {
    int height;
    if ( T != NULL ) {
        height = 1 + max(get_height(T->left), get_height(T->right));
    }
    return height;
}

int get_node_count(TreeNode *T) {
    int cnt;
    if ( T != NULL ) {
        cnt = 1 + get_node_count(T->left) + get_node_count(T->right);
    }
    return cnt;
}

TreeNode *search(TreeNode *T, int key) {
    while ( T != NULL ) {
        if ( T->data == key ) {
            return T;
        } else if ( T->data > key ) {
            T = T->left;
        } else {
            T = T->right;
        }
    }
    return NULL;
}

TreeNode *search_recur(TreeNode *T, int key) {
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->data == key ) {
        return T;
    } else if ( T->data > key ) {
        search_recur(T->left, key);
    } else {
        search_recur(T->right, key);
    }
}

void insert_node(TreeNode **root, int key) {
    TreeNode *p = NULL, *t = *root; // p : 부모노드 t : 현재노드
   
    while ( t != NULL ) {
        if ( t->data == key ) {
            return;
        }
        p = t;
        if ( t->data > key ) {
            t = t->left;
        } else {
            t = t->right;
        }
    }

    TreeNode *n = create_node(key, NULL, NULL); // new_node

    if ( p != NULL ) {
        if ( p->data > key ) {
            p->left = n;
        } else {
            p->right = n;
        }
    } else {
        *root = n;
    }
}

void delete_node(TreeNode **root, int key) {
    TreeNode *p = NULL, *t = *root;
    
    while ( t != NULL && t->data != key ) {
        p = t;
        if ( t->data > key ) {
            t = t->left;
        } else {
            t = t->right;
        }
    }

    if ( t == NULL ) {
        perror("no key");
    } else if ( t->left == NULL && t->right == NULL ) {
        if ( p != NULL ) {
            if ( p->left == t ) {
                p->left = NULL;
            } else {
                p->right = NULL;
            }
        } else {
            *root = NULL;
        }
    } else if ( t->left == NULL || t->right == NULL ) {
        TreeNode *child = (t->left != NULL) ? t->left : t->right;
        if ( p != NULL ) {
            if ( p->left == t ) {
                p->left = child;
            } else {
                p->right = child;
            }
        } else {
            *root = child;
        }
    } else {
        TreeNode *succ_p = t, *succ = p->right;
        while ( succ->left != NULL ) {
            succ_p = succ;
            succ = succ->left;
        }
        if ( succ_p->left == succ ) {
            succ_p->left = succ->right;
        } else {
            succ_p->right = succ->right;
        }
        t->data = succ->data;
        t = succ;
    }
    free(t);
}

int main(void) {
    TreeNode *tree = NULL;
    insert_node(&tree, 6);
    insert_node(&tree, 2);
    insert_node(&tree, 1);
    insert_node(&tree, 4);
    insert_node(&tree, 3);
    insert_node(&tree, 5);
    insert_node(&tree, 7);
    insert_node(&tree, 9);
    insert_node(&tree, 8);
    in_order(tree);
    delete_node(&tree, 7);
    in_order(tree);
}