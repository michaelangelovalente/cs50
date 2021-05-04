// Implements a dictionary's functionality
/*
#include <stdbool.h>

#include "dictionary.h"*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/michaelangelovalente/Desktop/extra/cs50/pset5/speller/dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    bool wordExists; 
    struct node *next[10]; // Replace with N
}
node;

// Number of buckets in hash table
//const unsigned int N = 1;
const unsigned int N = 10;

// Hash table
node *table[10];

//number of words inside the dictionary
unsigned long number_of_words = 0;


/*******************************************************************************************/
/*Implement:
load done
hash done
size DONE
check 
unload
*/
unsigned long hasher(const char *word);

int main(int argc, char *argv[]){
    //char *str = "abbc";
    //printf("%lu\n", hasher( str));
    //unsigned long tmp1  = 
    bool y = true;
    unsigned long tmp[7] ;
    char *str[7] = {"cat","cazzo", "catastrophe","cat", "dragon", "abc", "dragon"};

    for(int i = 0; i < 7; i++ ){
        tmp[i] = hasher(str[i]); 
    }

    char *testStr = "/home/michaelangelovalente/Desktop/extra/cs50/pset5/speller/test/small.txt"; 
    if( !load(testStr) ){
        printf("Something went wrong :(\n");
        return 0;
    }


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
   
    char wrd[LENGTH];
    unsigned long hash_val = 0;

    
    node *traverse;
    while(!feof(ptrFile)){
        fscanf(ptrFile, "%s", wrd);
        hash_val = hasher(wrd);
        //try, optimizing by getting rid of first iteration i == -1 and calc i at declaration
        //See unload
        for(int i = -1; hash_val > 0 ; hash_val = hash_val / 10 ){

            //first iteration
            if(i == -1){
                i = hash_val % 10;
                if( table[i] == NULL ){
                    table[i] = calloc( 1, sizeof(node) );
                    //IF NULL ecc
                    
                }
                //table[i]
                //IF MALLOC NULL ECC...
                traverse = table[i];
                //traverse->nextExists = false;
               
            }else{
                //allocating space for node (that also contains a table of *node[26])
                i = hash_val % 10;
                if( traverse->next[i] != NULL ){
                    traverse = traverse->next[i];
                    
                }else{
                    traverse->next[i]  = calloc( 1, sizeof(node) );
                    //IF MALLOC NULL ECC...
                    traverse = traverse->next[i];
                }
                
                
                
            }
            
        }

        //need to check if already loaded with "isLoaded"
        //traverse->word = wrd;
        //copy wrd from external dictionary to dictionary in mem.
        strcpy(traverse->word, wrd); //dst <--src
        traverse->wordExists = true;
        number_of_words++;
    }

    fclose(ptrFile);
    return true;
}



//source: http://www.cse.yorku.ca/%7Eoz/hash.html
//hashes a word using the djb2 algorithm;
unsigned long hasher(const char *word){
        unsigned long hash = 5381;
        int c;

        while (c = tolower(*word++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
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


///IMMMMM HEREE
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
   unsigned long hash_valc = hasher(word);
   node *traverser = NULL;
   traverser = table[hash_valc%10];
   hash_valc = hash_valc/10 ;
   for(int i = hash_valc%10; hash_valc > 0; hash_valc = hash_valc/10 ){
       if(traverser->next[i]->wordExists){
           return true;
       }
       i = hash_valc%10;
       traverser = traverser->next[i];
       
   }
    return false;
}

