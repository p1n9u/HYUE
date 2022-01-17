#include <stdio.h>

#define MAX_LIST_SIZE 5

typedef int element;

typedef struct ArrayListType {
    int list[MAX_LIST_SIZE];
    int length;
} ArrayListType;

void init(ArrayListType *L) {
    L->length = 0;
}

void clear(ArrayListType *L) {
    L->length = 0;
}

int is_empty(ArrayListType *L) {
    return (L->length == 0);
}

int is_full(ArrayListType *L) {
    return (L->length == MAX_LIST_SIZE);
}

void add_first(ArrayListType *L, element item) {
    if ( is_full(L) ) {
        perror("error");
    } else {
        for ( int i=L->length; i>0; i-- ) {
            L->list[i] = L->list[i-1];
        }
        L->list[0] = item;
        L->length++;
    }
}

void add_last(ArrayListType *L, element item) {
    if ( is_full(L) ) {
        perror("error");
    } else {
        L->list[L->length] = item;
        L->length++;
    }
}

void add(ArrayListType *L, int pos, element item) {
    if ( is_full(L) || pos<0 || pos>L->length ) {
        perror("error");
    } else {
        for ( int i=L->length; i>pos; i-- ) {
            L->list[i] = L->list[i-1];
        }
        L->list[pos] = item;
        L->length++;
    }
}

void delete(ArrayListType *L, int pos) {
    if ( is_empty(L) || pos<0 || pos>L->length-1 ) {
        perror("error");
    } else {
        for ( int i=pos; i<L->length-1; i++ ) {
            L->list[i] = L->list[i+1];
        }
        L->length--;
    }
}

void replace(ArrayListType *L, int pos, element item) {
    if ( is_empty(L) || pos<0 || pos>L->length-1 ) {
        perror("error");
    } else {
        L->list[pos] = item;
    }
}

void is_in_list(ArrayListType *L, element key) {
    if ( is_empty(L) ) {
        perror("error");
    } else {
        for ( int i=0; i<L->length; i++ ) {
            if ( L->list[i] == key ) {
                printf("key [%d] is in list pos [%d]\n", key, i);
                return;
            }
        }
    }
    printf("key [%d] is not in list\n", key);
}

void get_entry(ArrayListType *L, int pos) {
    if ( is_empty(L) || pos<0 || pos>L->length-1 ) {
        perror("error");
    } else {
        printf("pos [%d] : entry [%d]\n", pos, L->list[pos]);
    }
}

void get_length(ArrayListType *L) {
    printf("length : [%d]\n", L->length);
}

void display(ArrayListType *L) {
    printf("[ ");
    for ( int i=0; i<L->length; i++ ) {
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