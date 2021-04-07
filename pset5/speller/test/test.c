#include <stdio.h>

#include <stdlib.h>
#include "/home/michaelangelovalente/Desktop/cs50_2021/pset5/speller/dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
//const unsigned int N = 1;
 const unsigned int N = 100;

// Hash table
node *table[100];


unsigned long hasher(unsigned char *str);
bool load(const char *dictionary);

int main(int argc, char *argv[]){
    
    //load(argv[1]);
    /*printf("%d\n", (2<<2));
    printf("%d\n", (8>>3));*/
    
    unsigned char *str[] = {"Aezo", "Helo", "ZlO", "heko", "Heko"};

    int i = 0;

    while (i < 5  ){
        printf("%s\n", (str)[i]);
        printf("%lu\n", hasher((str)[i] ));
        
        i++;
    }

    printf("%d---ssssss\n", EOF);
    //printf("%lu\n", hash(str));
    



}


// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{
    // TODO

    FILE *ptrFile = fopen(dictionary, "r");
    //opens the file and checks for success, otherwise return false.
    
    if (ptrFile == NULL){
        return false;
    }
    //ptrFile now points to the address of the first char of the file

    //stores words in char *words
    char *words;
    int numbOfWords = 0;

    while(numbOfWords != EOF) {
        numbOfWords = fscanf(ptrFile, "%s", words);
        ////hashfunction
        //load word on hastable

    } 


    
    return true;
}



//http://www.cse.yorku.ca/%7Eoz/hash.html
//unsigned long;
unsigned long hasher(unsigned char *str){
    unsigned long  hash = 5381;
    int c;

    while(c = *str++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }
    return hash;
}