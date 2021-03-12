#include <stdio.h>

void swap(int *a, int *b);
void insertionSort(int *arr, int arr_size);

int main(){
    int array[] = {99, 5, 6, 1, 2,3, 12, 1};
    //int *ptr_arr = &array[0];
    int i, sizeofarray = (sizeof(array)/sizeof(array[0]));
    printf("Your array: ");
    for( i = 0; i < sizeofarray; i++ ){
        printf("[%d]", *(array + i));
    }
    putchar('\n');

    insertionSort(array, sizeofarray);

    printf("Your array: ");
    for( i = 0; i < sizeofarray; i++ ){
        printf("[%d]", *(array + i));
    }
    putchar('\n');

    return 0;
    
}


void insertionSort(int *arr, int arr_size){
    int i, j, tmp = 0;

    for(i = 0; i < arr_size; i++){
        //tmp = i;
        for (j = i; j < arr_size; j++){
            if ( *(arr + j) < *(arr + tmp)){
                tmp = j;
            }
        }
        swap((arr + i), (arr + tmp));
    }
    return;
}

//swapper saps using only two variables
    /*a = a + b
      b = a - b
      a = a - b */
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}