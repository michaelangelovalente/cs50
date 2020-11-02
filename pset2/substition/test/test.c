#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    /*if (strlen(*(argv + 1)) == 26){

    }*/
    char a[100] = {0};
     fgets(a, 100, stdin );
    printf("my string %s has a size of : %li\n", a, strlen(a) );
}