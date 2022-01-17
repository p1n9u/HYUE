int search_binary(int list[], int key, int low, int high) { 
    int middle = (low+high)/2; 
    if( key == list[middle] ) {
        return middle;
    } else if ( key < list[middle] ) {
        return search_binary(list, key, list[0], list[middle-1]);
    } else if ( key > list[middle] ) {
        return search_binary(list, key, list[middle+1], list[high]);
    } else {
        
    }
}

int search_binary2(int list[], int key, int low, int high) { 
    int middle;
    while ( low <= high ) {  
        middle = (low+high)/2;
        if( key == list[middle] ) {
            return middle;
        } else if ( key > list[middle] ) {
            low = middle+1;
        } else {
            high = middle-1;
        }
    } 
    return -1;
}