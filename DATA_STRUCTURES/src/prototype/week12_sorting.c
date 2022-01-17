#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct field {
    element x;
    element y;
} field;

field *arr[6];

field *create_field(element x, element y) {
    field *new_field = (field *)malloc(sizeof(field));
    if ( new_field == NULL ) {
        perror("malloc error!\n");
    } else {
        new_field->x = x;
        new_field->y = y;
        return new_field;
    }
}

int main(void) {

    srand(time(NULL));

    for ( int i=0; i<6; i++ ) {
        element r1 = rand()%10;
        element r2 = rand()%10;
        arr[i] = create_field(r1, r2);
    }

    printf("Initial Array : ");
    for ( int i=0; i<6; i++ ) {
        printf("[%d %d] ", arr[i]->x, arr[i]->y);
    }
    printf("\n");

    // sort
void bubble_sort(int list[], int n) {
    int tmp; 
    for ( int i=n-1; i>0; i-- ) { 
        for ( int j=0; j<i; j++) {
            if( list[j]>list[j+1] ) {   
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
}
    //    

    printf("Sorted Array : ");
    for ( int i=0; i<6; i++ ) {
        printf("[%d %d] ", arr[i]->x, arr[i]->y);
    }
    printf("\n");
    
    return 0;
}