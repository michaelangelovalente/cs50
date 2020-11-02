#include <stdio.h>

//functions
int coleman_liau_index(unsigned int lett, unsigned int words, unsigned int sent);

int main(){
 //float l_upper, s_upper;
    printf("%d\n", coleman_liau_index(65,14, 4) );
}


char *get_string(char *mystring);

//WORKS! HUZZAAA
//takes as input 3 integers: (# of letters, words and sentences) and 
//returns the Coleman_liau_index.
int coleman_liau_index(unsigned int lett, unsigned int words, unsigned int sent){
    //index = 0.0588 * L - 0.296 * S - 15.8
    return ( ( 0.0588 * (((float)lett/(float)words) * 100.0 ) ) - ( 0.296 * (((float)sent/(float)words) * 100.0) ) - 15.8 );
}
//https://cs50.harvard.edu/x/2020/psets/2/readability/#:~:text=index%20=%200.0588%20*%20L%20-%200.296%20*%20S%20-%2015.8