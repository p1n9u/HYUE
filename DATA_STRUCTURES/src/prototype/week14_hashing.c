#include <stdio.h>

typedef struct element {
	int value;
	int empty;
} element;

int hash(int key) {
	return (key%10);
}

int main(void) {
	int key, value;
  	element hash_table[10];
  	
  	for( int i=0; i<10; i++ ) {
    	hash_table[i].value=0;
   		hash_table[i].empty=-1;
  	}
  
    while(1) { 
    	printf("KEY와 VALUE를 입력하시오.\n");
    	scanf("%d %d", &key, &value);
 
	    if ( key == -1 ) {
    		printf("Done!\n");
     		break;
    	}

    	if ( hash_table[hash(key)].empty == -1 ) {
        	hash_table[hash(key)].empty = 1;
      		hash_table[hash(key)].value = value;
    	} else {
      		int k = key;
      		while ( hash_table[hash(k)].empty != -1 ) {
                k++;
        		if ( hash(k) == hash(key) ) {
          			printf("full\n");
                    return 0;
        		} 
            }
      		hash_table[hash(k)].empty = 1;
      		hash_table[hash(k)].value = value;
    	}

    	for( int i=0; i<10; i++ ) {
      		printf("hashtable[%d] :%d\n", i, hash_table[i].value);
    	}
	}

    return 0;
    
}