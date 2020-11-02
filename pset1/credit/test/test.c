#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void main(void){
    char str[] = "bbc" ;
    char *ptr = &str[0];
    if(*(ptr) == 'a' && *(ptr + 1) == 'b'){
        printf("its alive!\n");
    } 
    /*schar str[99] = {0};
    //printf("%s\n", str);
    char *ptr_str = str;

    fgets(ptr_str, 100, stdin );
    for(int i = 0; *(ptr_str + i) != '\0'; i++ ){
        //printf("%d: %c: %d\n",i, *(ptr_str + i),atoi(ptr_str));
    }*/
    /*
    for (int i = 0; i < 10; i ++){
        if(i%2){
            printf("[%d]true %d - \n",i, i%2);
        }else{
            printf("[%d]false %d - \n",i, i%2);
        }
        
    }
    printf("\n");*/
}