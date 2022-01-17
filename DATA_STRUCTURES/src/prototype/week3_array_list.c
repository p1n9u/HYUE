#include <stdio.h>

#define MAX_LIST_SIZE 5

typedef int element; 

typedef struct ArrayListType {
    element list[MAX_LIST_SIZE];
    int length;
} ArrayListType;

void init(ArrayListType *L) {
    L->length = 0;
}

void clear(ArrayListType *L){
    (L->length) = 0;
    printf("clear!\n");
}

int is_empty(ArrayListType *L) {
     return L->length == 0;
}

int is_full(ArrayListType *L) {
    return L->length == MAX_LIST_SIZE;
}

void add_first(ArrayListType *L, element item){
    if ( is_full(L) ){
        perror("already full!\n");
    } else {
        for ( int i=(L->length-1); i>=0; i-- ){
            L->list[i+1] = L->list[i];
        }
        L->list[0] = item;
        L->length++;
    }
}

void add_last(ArrayListType *L, element item){
    if ( is_full(L) ){
        perror("already full!\n");
    } else {
        L->list[(L->length)] = item;
        L->length++;
    }
}

void add(ArrayListType *L, int position, element item) {
    if( !is_full(L) && (position >= 0) && (position <= L->length) ) { 
        for( int i=(L->length-1); i>=position; i--) {
            L->list[i+1] = L->list[i];
        } 
        L->list[position] = item; 
        L->length++;
    }
}

element delete(ArrayListType *L, int position){
    element item;
    if ( is_empty(L) ){
        perror("empty!\n");
    } else if ( (position<0) || (position>=(L->length)) ) {
        perror("position error!\n");
    } else {
        item = L->list[position];
        for ( int i=position; i<(L->length-1); i++ ){
            L->list[i] = L->list[i+1];
        }
        (L->length)--;
        return item;
    }
}

void replace(ArrayListType *L, int position, element item){
    element rep_item = L->list[position];
    L->list[position] = item;
    printf("item[%d] : %d replace to %d\n", position, rep_item, L->list[position]);
}

void is_in_list(ArrayListType *L, element item){
    for ( int i=0;i<(L->length);i++ ){
        if ( L->list[i] == item ){
            printf("item %d is in list : item[%d]\n", item, i);
            return;
        }
    }
    printf("item %d is not in list\n", item);
}

void get_entry(ArrayListType *L, int position){
    if ( is_empty(L) ) {
        perror("empty!\n");
    } else if ( position > L->length || position < 0 ) {
        perror("position error!\n");
    } else {
        printf("item[%d] : %d\n", position, L->list[position]);
    }
}

void get_length(ArrayListType *L){
    printf("current length : %d\n", (L->length));
}

void display(ArrayListType *L){
    printf("[ ");
    for ( int i=0;i<(L->length);i++ ){
        printf("%d ", L->list[i]);
    }
    printf("]\n");
}

int main(void) {
    ArrayListType list1;
    init(&list1);
    display(&list1);
    for ( int i=0; i<MAX_LIST_SIZE+1; i++) {
        add_first(&list1, i);
    }
    display(&list1);
    clear(&list1);
    display(&list1);
    for ( int i=0; i<MAX_LIST_SIZE+1; i++) {
        add_last(&list1, i);
    }
    delete(&list1, 4);
    display(&list1);
    delete(&list1, 0);
    display(&list1);
    delete(&list1, 1);
    display(&list1);
    add(&list1, 1, 5);
    display(&list1);
    replace(&list1, 1, 2);
    display(&list1);
    is_in_list(&list1, 5);
    is_in_list(&list1, 2);
    get_entry(&list1, 5);
    get_entry(&list1, 2);
    get_length(&list1);
    return 0;
}