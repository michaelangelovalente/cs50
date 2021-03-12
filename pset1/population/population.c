#include <stdio.h>

int main(int argc, char *argv[]){
    
    
    //prompt starting population size
        //if n < 9 → reprompt

    //prompt ending population size
        //if less than ending population size < n → reprompt

    //int number of years required for population to reach te ending pop size
    //print result

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
    
    printf("Years:%d\n", llamas(startP, endP));
    return 0;
}

int llamas(int llamas, int newPop){
    int deadL = llamas/4;
    int bornL = llamas/3;
    int tmp = 0;
    while(llamas < newPop){
        tmp++;
        llamas = llamas - deadL + bornL;
        deadL = llamas/4;
        bornL = llamas/3;
        
    }
    return tmp;
}