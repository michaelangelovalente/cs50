#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BUFFER 2000

typedef struct {
    int sentences;
    int words;
    int letts;
}coleman_types;

//functions
int coleman_liau_index(unsigned int lett, unsigned int words, unsigned int sent);
char *get_string();
coleman_types coleman_ctr(char *usr_in);




int main(){
    char str[BUFFER];
    char *ptr_str;
    coleman_types numberOf = {0};

    ptr_str = &str[0];
    printf("Text: ");
    fgets(ptr_str, BUFFER-10, stdin);
    numberOf = coleman_ctr(ptr_str);
    int coleman_idx = coleman_liau_index(numberOf.letts, numberOf.words, numberOf.sentences);
    
    if (coleman_idx >= 16){
        printf("Grade 16+\n");
    }else if (coleman_idx <= 1){
        printf("Before Grade 1\n");
    }else{
        printf("Grade %d\n", coleman_idx);
    }

}

coleman_types coleman_ctr(char *usr_in){
    coleman_types ctr = {0};
    for(int i = 0; *(usr_in + i) != '\0'; i++){
        if (isalpha(*(usr_in + i))) {
            ctr.letts++;
        }
        if(*(usr_in + i) == '.' || *(usr_in + i) == '?' || *(usr_in + i) == '!' ){
            ctr.sentences++;
        }
        if((*(usr_in + i) == ' ' && *(usr_in + i+1) != ' ') || (*(usr_in + i) == '.' && (*(usr_in + i+1) == '\n' || *(usr_in + i+1) == '\0'))   ){
            ctr.words++;
        }
    }
    return ctr;
}

//takes as input 3 integers: (# of letters, words and sentences) and 
//returns the Coleman_liau_index.
int coleman_liau_index(unsigned int lett, unsigned int words, unsigned int sent){
    //index = 0.0588 * L - 0.296 * S - 15.8
    return round(( ( 0.0588 * (((float)lett/(float)words) * 100.0 ) ) - ( 0.296 * (((float)sent/(float)words) * 100.0) ) - 15.8 ));
}
//https://cs50.harvard.edu/x/2020/psets/2/readability/#:~:text=index%20=%200.0588%20*%20L%20-%200.296%20*%20S%20-%2015.8