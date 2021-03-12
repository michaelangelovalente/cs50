#include <stdio.h>

void selection_sort(int *arr, size_t size_arr );
void swap(int *a, int *b );

int main(int argc, char **argv){
    int arr[] = {91, 23, 1, -9, 2, 5, 12, 24, 14, 17};
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    int i;
    for ( i = 0; i < size_arr; i++ ){
        printf("[%d]", *(arr + i));
    }
    putchar('\n');
    selection_sort(arr, size_arr);
    for ( i = 0; i < size_arr; i++ ){
        printf("[%d]", *(arr + i));
    }
    putchar('\n');

}

void selection_sort(int *arr, size_t size_arr ){
    int i, j;
    for( i = 0; i < size_arr; i++){
        for ( j = i + 1; j < size_arr; j++){
            if( *(arr + j) < *(arr + i) ){
                swap( (arr + j), (arr + i));
            }
        }
    }
}

void swap(int *a, int *b ){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return; 
}