// Implements a dictionary's functionality
/*
#include <stdbool.h>

#include "dictionary.h"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/michaelangelovalente/Desktop/extra/cs50/pset5/speller/dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next; // Replace with N
}
node;

// Number of buckets in hash table
//const unsigned int N = 1;
const unsigned int N = 10;

// Hash table
node *table[N];

//number of words inside the dictionary
unsigned long number_of_words = 0;


/*******************************************************************************************/
/*Implement:
load 
hash 
size 
check 
unload
*/

int main(int argc, char *argv[]){
printf("%d\n", 'a');
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}


/********************************************************************************/
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return number_of_words;
}



// Returns true if word is in dictionary, else false
bool check(const char *word)
{
   
    return true;
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
   
    char words[LENGTH];
    unsigned long hash_val = 0;

    return true;
}



//src: http://www.cse.yorku.ca/%7Eoz/hash.html
//hashes a word using the djb2 algorithm;
unsigned long hasher(const char *word){
    unsigned long  hash = 5381;
    int c;

    while(c = tolower(*word++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }
    return hash;
}