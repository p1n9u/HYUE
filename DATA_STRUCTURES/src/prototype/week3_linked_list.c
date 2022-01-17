#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode { 
    element data;
    struct ListNode *link; 
} ListNode;

ListNode *create_node(element item, ListNode *link) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    if ( new_node == NULL ){
        perror("malloc error!\n");
    } else {
        new_node->data = item;
        new_node->link = link;
        return new_node;
    }
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) { 
    if( *phead == NULL ) { 
        new_node->link = NULL;
        *phead = new_node;
    } else if ( p == NULL ) { 
        new_node->link = *phead;
        *phead = new_node;
    } else { 
        new_node->link = p->link; 
        p->link = new_node;
    }
}

void insert_node_after_value(ListNode *head, int key, ListNode *new_node){
    ListNode *p = head;
    while ( p != NULL ) {
        if ( p->data == key ) {
            new_node->link = p->link;
            p->link = new_node;
            return;
        }
        p = p->link;    
    }
    perror("No Key!\n");
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed) { 
    if( p == NULL ) {
        *phead = (*phead)->link; 
    } else {
        p->link = removed->link;
    }
    free(removed);
}

void remove_node_by_value(ListNode **phead, ListNode *head, int key){
    ListNode *tmp = NULL, *cur1 = head, *cur2 = head->link;
    if ( (*phead)->data == key ) {
        tmp = *phead;
        *phead = (*phead)->link;
        free(tmp);
        return;
    } else {
        while ( cur2 != NULL ) {
            if ( cur2->data == key ) {
                tmp = cur2;
                cur1->link = cur2->link;
                free(tmp);
                return;
            }
            cur1 = cur1->link;
            cur2 = cur2->link;
        }
    }
    perror("No Key!\n");
}

void replace_node_by_value(ListNode **phead, ListNode *head, int key, ListNode *new_node){
    ListNode *tmp = NULL, *cur1 = head, *cur2 = head->link;
    if ( (*phead)->data == key ){
        tmp = *phead;
        new_node->link = (*phead)->link;
        *phead = new_node;
        free(tmp);
        return;
    } else {
        while ( cur2 != NULL ) {
            if ( cur2->data == key) {
                tmp = cur2;
                new_node->link = cur2->link;
                cur1->link = new_node;
                free(tmp);
                return;
            }
            cur1 = cur1->link;
            cur2 = cur2->link;
        }
    }
    perror("No key!\n");
}

void display(ListNode *head) { 
    ListNode *p=head;
    while( p != NULL ) { 
        printf("%d->", p->data); 
        p = p->link; 
    }
    printf("\n");
}

void display_recur(ListNode *head) { 
    ListNode *p=head;
    if ( p != NULL ) { 
        printf("%d->", p->data); 
        display_recur(p->link);
    }
}

ListNode *search(ListNode *head, int x) { 
    ListNode *p;
    p = head;
    while( p != NULL ) {
        if( p->data == x ) { 
            return p;
        } 
        p = p->link;
    }
    return p;
}

ListNode *concat(ListNode *head1, ListNode *head2) {
    ListNode *p;
    if( head1 == NULL ) {
        return head2;
    } else if ( head2 == NULL ) {
        return head1;
    } else {
        p = head1;
        while( p->link != NULL ) {
            p = p->link; 
        }
        p->link = head2; 
        return head1;
    }
}

ListNode *reverse(ListNode *head) { 
    ListNode *p, *q, *r;
    p = head;  
    q = NULL;  
    while (p != NULL) {
        r = q;  
        q = p; 
        p = p->link;
        q->link =r;
    }
    return q;
}

int main(void) {
    ListNode *head1=NULL, *head2=NULL, *head3=NULL, *head4=NULL;
    /*
    create_node
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->link = link;
    new-node->data = data;
    */
    for (int i=1;i<=5;i++) { 
        ListNode *new_node = create_node(i, NULL); 
        insert_node(&head1, NULL, new_node); 
    } 
    for (int i=6;i<=10;i++) { 
        ListNode *new_node = create_node(i, NULL); 
        insert_node(&head2, NULL, new_node); 
    }
    printf("링크드리스트1 전체출력\n"); 
    display(head1); 
    printf("링크드리스트2 전체출력\n"); 
    display(head2); 
    printf("링크드리스트 합치기\n"); 
    head3 = concat(head2, head1); 
    display(head3);
    printf("새로운 노드 11을 4 뒤에 넣기\n"); 
    ListNode *new_node = create_node(11, NULL);
    insert_node_after_value(head3, 4, new_node); 
    display(head3); 
    printf("새로운 노드 12을 0 (없는 값) 뒤에 넣기\n"); 
    ListNode *new_node2 = create_node(12, NULL);
    insert_node_after_value(head3, 0, new_node2); 
    display(head3); 
    printf("노드 11을 삭제하기\n"); 
    remove_node_by_value(&head3, head3, 11); 
    display(head3); 
    printf("노드 1을 삭제하기\n"); 
    remove_node_by_value(&head3, head3, 1); 
    display(head3); 
    printf("노드 10을 삭제하기\n"); 
    remove_node_by_value(&head3, head3, 10); 
    display(head3);
    printf("노드 1을 삭제하기\n"); 
    remove_node_by_value(&head3, head3, 1); 
    display(head3);
    printf("노드 2을 10으로 대체하기\n");
    ListNode *new_node3 = create_node(10, NULL);
    replace_node_by_value(&head3, head3, 2, new_node3);
    display(head3);
    printf("노드 9을 11으로 대체하기\n");
    ListNode *new_node4 = create_node(11, NULL);
    replace_node_by_value(&head3, head3, 9, new_node4);
    display(head3);
    printf("링크드리스트 역순\n");
    head4 = reverse(head3);
    display(head4);
    return 0;
}