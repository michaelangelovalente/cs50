#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/michaelangelovalente/Desktop/extra/cs50/pset5/speller/dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next[10];//*next[N];
}
node;

// Number of buckets in hash table
//const unsigned int N = 1;
 const unsigned int N = 10;

// Hash table
node *table[10];

//number of words inside the dictionary
unsigned long number_of_words = 0;


unsigned long hasher(const char *str);
bool load(const char *dictionary);

int main(int argc, char *argv[]){
    
    //load(argv[1]);
    /*printf("%d\n", (2<<2));
    printf("%d\n", (8>>3));*/
   printf("%d", load("small"));
   char *s = "cat";
   unsigned long x = hasher(s);
   int i = 0;
   
   node *traverse;
   while( 1 ){

       printf("%d\n", i);
       printf("word is: %lu\n", x);
       if(i == 0){
           printf("i is%d : content of traverse: %p table[%d]->%p\n", i, traverse, x%10,  table[x%10]);
           traverse = table[ x % 10 ];
           i++;
           continue;
       }
       x = x/10;
       printf("i is%d : content of traverse: %p table[%d]->%p\n", i, traverse, x%10,  traverse->next[x%10]);
       if(x < 10){
           break;
       }
       traverse = traverse->next[ x % 10 ];
       

       
       i++;
   }

   printf("%p -> word: %s and next: %p\n", traverse, traverse->word, traverse->next );
   for(int j2 = 0; j2 < 10; j2++){
       printf("traverse->next[%d] : %p\n", j2, traverse->next[j2]);
   }
    printf("\n");



    printf("\n------------------------Checking if function check works--------------------------------\n");
    
    char *tmpstr = "cat";
    unsigned long tmpN = hasher(tmpstr);
    printf("hash value for %s is: %lu\n",tmpstr , tmpN );
    bool isPresent = check(tmpstr);
    if( isPresent  ){
        printf("%s is in dictionary!\n");
    }else{
        printf("%s is not in dictionary!\n");
    }

}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned long hash = hasher(word);
    node *traverse;

    //No words in dictionary --> word is not in dictionary    
    if(number_of_words == 0){
        printf("case 1\n");
        return false;
    }


    for( int i = 1; hash  > 10;){
        if( i == 1){
            //table[idx] is empty: word is not present in dictionary
            if(table[hash % 10] == NULL){
                printf("case 2\n");
                return false;   
            }
            traverse = table[hash % 10];
            i++;
        }else{
            //hash is incorrect --> word is not in dictionary
            if(traverse->next[ hash % 10] == NULL){
                printf("case 3\n");
                return false;
            }
            traverse = traverse->next[ hash % 10];
        }
        hash = hash/10;
        
    }

    //last part of hash is incorrect --> word is not in dictionary
    if(traverse->next[hash] == NULL){
        printf("case 4\nValue of hash is:%lu\npointer of traverse is %p\n and at index %lu there should 
        be an address: %p\n at this structure there should be the word %s\n", hash, traverse, hash, traverse->next[hash], traverse->word   );
        return false;
    }

    //trie using hash value leads to a word --> word is in dictionary.
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

    while( fscanf(ptrFile, "%s", words) != EOF ){
        
        //hash the word
        unsigned char *s = words;
        hash_val = hasher(s);
        printf("hash value for %s is: %lu\n", words, hash_val);
        

        //node *traverse_table;
        //store a word inside a trie based on its hash value
        int i = 0;
        node *traverser;
        for(int idx = -1;  i != -99 ; idx = hash_val / 10 ){
            i++;//// Try to get rid of it later
            
            //first iteration: access the main table
            if(idx == -1 ){//You can replace idx with i
               
                table[ hash_val % 10 ] = malloc( sizeof(n ode) );
                if(table[ hash_val % 10 ] == NULL){
                    return false;
                }
                traverser = table[hash_val % 10];

            }else if( idx >= 10){
                
                traverser->next[ idx % 10] = malloc( sizeof(node) );
                if(traverser->next[ idx % 10] == NULL){
                    return false;
                }
                
                traverser = traverser->next[ idx % 10];
                hash_val = hash_val / 10;
                
            }else{
                //final step:
                //word insertion
                //table[idx % 10]->word = words 
                strcpy(traverser->word, s);
                
                for(int j = 0; j < 10; j++){
                    traverser->next[j] = NULL;
                }
                i = -99;
                number_of_words++;

            }
            

        }
        
    }

    return true;
}



//src: http://www.cse.yorku.ca/%7Eoz/hash.html
//hashes a word using the djb2 algorithm;
unsigned long hasher(const char *str){
    unsigned long  hash = 5381;
    int c;

    while(c = *str++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }
    return hash;
}