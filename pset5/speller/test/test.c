#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/michaelangelovalente/Desktop/extra/cs50/pset5/speller/dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next//*next[N];
}
node;

// Number of buckets in hash table
//const unsigned int N = 1;
 const unsigned int N = 10;

// Hash table
node *table[10];


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
    
    //printf("%d\n", load("small"));
    //printf("The address of the table is: %p\n",table );

    /*
    for(i = 0; i < 10 ; i++){
        //printf("addr[%p]-->content:%s and %p", table[i],(*table[i]).word, (*table[i]).next );
        printf("addr[%p]\n", table[i] );
    }*/


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

    //allocates memory for main table
    //table = malloc(sizeof(table[N] ));
    


    //stores words in char *words
    char *words[LENGTH];
    int hash_val = 0;

    while( fscanf(ptrFile, "%s", words) != EOF ){
        printf("-> %s\n", words);//prints out word by word from <dictionary>.txt
        
        
        //hash the word
        hash_val = hasher(words);

        //node *traverse_table;
        //store a word inside a trie based on its hash value
        for(int idx = -1; idx != 0 ; idx = hash_val / 10 ){
            
            //first iteration: access the main table
            if(idx == -1 ){
                //allocate space for a new table of size N
                //place new table of size n inside main table
                table[ hash_val % 10 ] = malloc( sizeof(table[N]) );
                //IF table[i] = NULL ecc...

                //idx = hash_val;
                printf("case1\n");

            }else if( idx >= 10){
                table[idx % 10] = malloc( sizeof(table[N]) );
                //IF table[i] = NULL ecc...
                //IF table[i] = NULL ecc...
                hash_val = hash_val / 10;
                printf("case2\n");
            }else{
                //word insertion

                table[idx % 10] = malloc(sizeof(node));
                //IF table[i] = NULL ecc...

                table[idx % 10]->next = NULL;
                //stcpy
                //table[idx % 10]->word = words;
                strcpy(table[idx % 10]->word, words);
                idx = hash_val = 0; //////////////////////// might wanna modify this later....
                printf("case3\n");

            }
            

        }
        //apply to table
    }

    return true;
}



//src: http://www.cse.yorku.ca/%7Eoz/hash.html
//hashes a word using the djb2 algorithm;
unsigned long hasher(unsigned char *str){
    unsigned long  hash = 5381;
    int c;

    while(c = *str++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }
    return hash;
}