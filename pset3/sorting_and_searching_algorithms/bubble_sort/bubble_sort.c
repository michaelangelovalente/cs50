#include <stdio.h>

void bubble_sort(int *array_n, int size_of_arr);

int main(){
    int n[] = {5, 2, 1, 3, 6, 4};
    int *ptr_n = &n;
    int len_n = sizeof(n)/sizeof(n[0]);
    int i;
    printf("Initial array: ");
    for(i = 0; i <  len_n; i ++){
        printf("[%i]", *(ptr_n + i));
    }
    putchar('\n');
    putchar('\n');

    bubble_sort(ptr_n, len_n );

    putchar('\n');
    printf("Final array: ");
    for(i = 0; i <  len_n; i ++){
        printf(" [%i]", *(ptr_n + i));
    }
    putchar('\n');

    
}

//bleh!--> BIG_O(n^2) O //**Omega(n)**//
void bubble_sort(int *array_n, int size_of_arr){
    int swap_ctr = -1;
    int i, j, x, y; 
    
    for(i = 0; i <(size_of_arr); i++ ){
        swap_ctr = 0;
        printf("Array Size: %i Iteration number %i\n", size_of_arr, i+1);
        for (j = 1; j < (size_of_arr - i); j++ ){
            printf("is [%d] > [%d]? ",*(array_n - 1 + j), *(array_n + j));
            if ( *(array_n - 1 + j) > *(array_n + j)  ){
                printf("yes! ---> new Array:");
                swap_ctr++;
                swapper((array_n - 1 + j), (array_n + j));
                for(x = 0; x < size_of_arr; x++){
                    if (x < j){
                        printf("[%d]", *(array_n + x));
                    } else if(x == size_of_arr-1){
                        putchar('\n');
                    }else {
                        printf(" %d ", *(array_n + x));
                    }
                }
                
            }else{
                printf(" no! --> old Array: ");
                for(x = 0; x < size_of_arr; x++){
                    if (x < j){
                        printf("[%d]", *(array_n + x));
                    } else if(x == size_of_arr-1){
                        putchar('\n');
                    }else {
                        printf(" %d ", *(array_n + x));
                    }
                }
            }
            if(swap_ctr == 0){
                printf("No more swaps needed");
                return;
            }
            //printf("Array at ");
        }

    }



}


//swapper saps using only two variables
    /*a = a + b
      b = a - b
      a = a - b */
void swapper(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}