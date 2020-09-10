//Template
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int compare(int a, int b){
    if(a>b)  
    	return 1;
    else 
       	return -1;
}

void swap(int *a, int *b){
    int temp = *a;
     *a = *b;
     *b = temp;
}

void BublleSort(int arr[], int size){
    int (*pfCompare)(int,int) = compare;

    int num;

    for(int i =1; i< size; i++){
        for(int j =0; j<size-i; j++){
            if(pfCompare(arr[j], arr[j+1])==1)
                swap(&arr[j],&arr[j+1]);
        }
    }
}    

/***************************************************************
define bubble sort that uses pointer to 'compare' function above
***************************************************************/


int main(){
    int n_array[SIZE] = {2,-9, 10, 15, 1, 3, -12, 5, 4, 1};

    //source code

    printf("before bubble sort\n");
    for(int i = 0; i<SIZE; i++){
        printf("%d ", n_array[i]);
    }
    printf("\n");

    BublleSort(n_array, SIZE);

    printf("after bubble sort\n");
    for(int i = 0; i<SIZE; i++){
        
        printf("%d ", n_array[i]);
        
    }
    printf("\n");

    return 0;
}
