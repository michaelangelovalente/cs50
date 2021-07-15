#include <stdio.h>

int main(int argc, char *argv[]){

    int startP = 0;
    int endP = -1;
    do{
        printf("Start size:");
        scanf("%d", &startP);
    }while(startP < 9);

    do{
        printf("End size:");
        scanf("%d", &endP);
    }while(endP < startP);

    printf("Years: %d\n", llamas(startP, endP));
    return 0;
}

int llamas(int llamas, int newPop){
    int deadL = 0;
    int bornL = 0;
    int tmp = 0;
    while(llamas < newPop){
        deadL = llamas/4;
        bornL = llamas/3;
        llamas = llamas - deadL + bornL;
        tmp++;

    }
    return tmp;
}