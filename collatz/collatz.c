#include <stdio.h>
#include <stdlib.h>

int collatz(int n);
int main(int argc, char *argv[]){

    int x = collatz(8);
    
}

int collatz(int n){
    //base case
    if(n == 1){
        printf("Final result: 1\n");
        return n;
        
    }
    //n is even
    if (n%2 == 0){
        printf("n(%d) is even, n is now (%d)\n", n, n/2);
        return 1 + collatz(n/2);
    //n odd
    }else {
        printf("n(%d) is odd, n is now (%d)\n", n, 3*n + 1);
        return 1 + collatz(3*n + 1);
    }
}