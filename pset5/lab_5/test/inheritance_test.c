/*
    1 person  2 allele ( different form of a gene)
    3 possible alleles (A,B and O) --> Each person has 2, possibly the same, possibly different.
    Each of a child's parent randomly passes one of their two blood types alleles to their child
    Possibile blood type combination:
        OO, OA, OB, AO, AA, AB, AB, BO, BA, and BB

        example:
        parent1 --> blood type: AO
        parent2 --> blood type: BB 
        child possibile blood type: AB, OB

        parent1 --> blood type: AO
        parent2 --> blood type: OB
        child possible blood type: AO, AB, OO, OB


 
*/
// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

person *create_family(int generations);
char random_allele();
void free_family(person *p);

int main(int argc, char *argv[]){
    // Seed random number generator
    srand(time(0));
   person *child = create_family(3);
   person *traverse_family = child;

            //recursively print...
        printf("child: [%c%c] -->Parent1[%c%c] and Parent2[%c%c] ", traverse_family->alleles[0], traverse_family->alleles[1], 
        traverse_family->parents[0]->alleles[0], traverse_family->parents[0]->alleles[1], 
        traverse_family->parents[1]->alleles[0], traverse_family->parents[1]->alleles[1] );

        free_family(child);
        
        /*
        printf("child: [%c%c] -->Parent1[%c%c] and Parent2[%c%c] ", traverse_family->alleles[0], traverse_family->alleles[1], 
        traverse_family->parents[0]->alleles[0], traverse_family->parents[0]->alleles[1], 
        traverse_family->parents[1]->alleles[0], traverse_family->parents[1]->alleles[1] );
    */
   

    
  
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if( p->parents[0] == NULL && p->parents[1] == NULL ){
        
        free(p);
        p = NULL;
        return;
    }

    
    // TODO: Free parents
    free_family(p->parents[0]);
    p->parents[0] = NULL;
    free_family(p->parents[1]);
    p->parents[1] = NULL;
    
    // TODO: Free child
    free_family(p);
    p = NULL;
    
}


// Create a new individual with `generations` /// <---
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *new_person = malloc(sizeof(person));
    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        //parent 1
        new_person->parents[0] = create_family(generations - 1);


        //parent 2
        new_person->parents[1] = create_family(generations - 1);


        // TODO: Randomly assign child alleles based on parents
        int idx = rand() %2;
        new_person->alleles[0] = new_person->parents[idx]->alleles[rand()%2];
        if(idx == 0){
            idx = 1;
        }
        new_person->alleles[1] = new_person->parents[idx]->alleles[rand()%2];

    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        new_person->parents[0] = NULL;

        new_person->parents[1] = NULL;
        
        // TODO: Randomly assign alleles
        new_person->alleles[0] = random_allele();

        new_person->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return new_person;
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}


/*
typedef struct two{
    struct two *num[2];
    int a, b, c;
    
}
two;

int main(int argc, char *argv[]){

    person a;

    printf("%d\n", sizeof(person));


    printf("%d\n", sizeof(a.parents));
    printf("%d\n", sizeof(a.alleles));
    printf("%d\n", sizeof(two));




}*/