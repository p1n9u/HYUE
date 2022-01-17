// selection_sort
void selection_sort(int list[], int n) { 
    int least, tmp; 
    for ( int i=0; i<n-1; i++ ) { 
        least = i; 
        for ( int j=i+1; j<n; j++ ) {
            if( list[j]<list[least] ) {
                least = j;
            }
        }
        tmp = list[i];
        list[i] = list[least];
        list[least] = tmp;
    }
}

// insertion_sort
void insertion_sort(int list[], int n) {
    int key;
    for ( int i=1; i<n; i++ ) {
        key = list[i];
        for ( int j=i-1; j>=0 && list[j]>key; j-- ) {
            list[j+1] = list[j];
            list[j] = key;
        }
    }
}

// bubble_sort
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

// shell_sort
void inc_insertion_sort(int list[], int first, int last, int gap) {
    int key; 
    for ( int i=first+gap; i<=last; i=i+gap ) { 
        key = list[i]; 
        for( int j=i-gap; j>=first && key<list[j]; j=j-gap ) {
            list[j+gap]=list[j];
        } 
        list[j+gap]=key;
    }
}

void shell_sort(int list[], int n) { 
    for( int gap=n/2; gap>0; gap=gap/2 ) { 
        if( (gap%2) == 0 ) {
            gap++;
        } 
        for( int i=0; i<gap; i++ ) {
            inc_insertion_sort(list, i, n-1, gap);
        }
    }
}

// merge_sort
int sorted[MAX_SIZE]; 

void merge(int list[], int left, int mid, int right) { 
    int i, j, k, l;
    i=left; j=mid+1; k=left; 
    while ( i<=mid && j<=right ) { 
        if ( list[i]<=list[j] ) {
            sorted[k++] = list[i++];
        } else {
            sorted[k++] = list[j++];
        }
    }
    if ( i>mid ) {
        for ( l=j; l<=right; l++) {
            sorted[k++] = list[l];
        }
    } else { 
        for ( l=i; l<=mid; l++ ) {
            sorted[k++] = list[l];
        }
    }
    for ( l=left; l<=right; l++ ) { 
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right) { 
    int mid;
    if( left<right ) { 
        mid = (left+right)/2;          
        merge_sort(list, left, mid);    
        merge_sort(list, mid+1, right); 
        merge(list, left, mid, right);
    }
}

// quick_sort
int partition(int list[], int left, int right) {
    int pivot, tmp; 
    int low, high;
    low = left;                  
    high = right+1; 
    pivot = list[left]; 
    do {
        do {
            low++; 
        } while( low<=right &&list[low]<pivot ); 
        do {
            high--; 
        } while( high>=left && list[high]>pivot ); 
        if( low<high ) {
            tmp = list[low];
            list[low] = list[high];
            list[high] = tmp;
        }
    } while( low<high );

    tmp = list[left];
    list[left] = list[high];
    list[high] = tmp; 
    return high; 
}

void quick_sort(int list[], int left, int right) {
    if ( left<right ) {     
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);  
    }
}

int main(void) {

    return 0;
}