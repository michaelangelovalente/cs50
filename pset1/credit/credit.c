#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define BUFFERSIZE 100



long get_long();
int creditCard(long credit_n, int n_digits);

int main(void){
    int i;
    long c_num = -1;
    long tmp[2] = {0};
    while (c_num == -1){
        printf("Number: ");
        c_num = get_long();
    }
    long c_num_save = c_num;
    for (i = 1; c_num > 0 ;i++){
        if (i%2){
            tmp[1] += (c_num%10);
        }else{
            if ( (c_num%10)*2 >= 10){
                tmp[0] += (((c_num%10)*2)%10) + ((c_num%10)*2)/10;
            }else{
                tmp[0] += (c_num%10)*2;
            }
        }
        c_num = c_num/10;
    }

    printf("test:%ld\n",tmp[0] + tmp[1]);
    if ( !((tmp[0] + tmp[1]) % 10)){
        if(creditCard(c_num_save ,i-1) == 3){
            printf("VISA\n");    
        }
        if(creditCard(c_num_save ,i-1) == 2){
            printf("MASTERCARD\n");    
        }
        if(creditCard(c_num_save ,i-1) == 1){
            printf("AMEX\n");    
        }
        if(creditCard(c_num_save ,i-1) == -1){//Could be optimized...
            printf("INVALID\n");    
        }

    }else{
        printf("Invalid\n");
    }

}
//takes a credit card number and its length and returns 3--> Visa, 2 --> MasterCard, 1 --> AmericanExpress, otherwise -1
int creditCard(long credit_n, int n_digits){
    int first_two_digits = (int)(credit_n / (long)(pow(10, (double)(n_digits - 2) )));//(long)(10 ^ (n_digits - 2) )  ;
    
    //Visa == 3
    if (( n_digits == 13 || n_digits == 16) && ((first_two_digits)/10) == 4 ){
        return 3;
    }
    //MasterCard == 2
    if ( n_digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55)){
        return 2;
    }
    // American Express == 1
    if (( n_digits == 15) &&(first_two_digits ==34 || first_two_digits == 37) ){
        return 1;
    }
    return -1;
}
//takes user input(string) from STDIN and returns its equivalent in long; if the string contains non digits it will return -1
long get_long(){
    char num[BUFFERSIZE];
    char *ptrStr = &num[0];
    long final = 0;
    fgets(ptrStr, 95, stdin);
    int stringLen = strlen(num) - 1; // -1 to get rid of \n char.
    for(int i = 0; i < stringLen; i++){
        if(!isdigit( *(ptrStr + i) )){
            return -1;
        }
    }
    final = atol(num);
    return final;
}