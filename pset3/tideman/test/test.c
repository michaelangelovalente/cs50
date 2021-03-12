#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;


bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner();

void swap(pair *a, pair *b );
int cycles(int winner, int loser);

int main(int argc, char *argv[]){

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        printf("Your ranks:");
        for (int x = 0; x < candidate_count; x++){
            printf("[%d]", ranks[x]);
        }
        printf("\n");

        record_preferences(ranks);

        printf("\n");
    }

    for(int x = 0; x < candidate_count; x++){
        for(int y = 0; y < candidate_count; y++ ){
            printf("[%d]", preferences[x][y]);
        }
        putchar('\n');
    }
    putchar('\n');

    add_pairs();
    //MAX * (MAX - 1) / 2
   ;
    for( int i = 0; i < pair_count; i++){
        printf("1 winner: %d - loser: %d\nScore:        %d -    %d\n\n", pairs[i].winner, pairs[i].loser, preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
    }
    printf("\n\n");

    sort_pairs();
    

    for( int i = 0; i < pair_count; i++){
        printf("2 winner: %d - loser: %d\nScore:    %d -        %d\n\n", pairs[i].winner, pairs[i].loser, preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
    }

    lock_pairs();

     for( int i = 0; i < candidate_count; i++){
         for(int j = 0; j < candidate_count; j++){
             printf("[%d]",locked[i][j]);
         }
         putchar('\n');
     }

    print_winner();
    //printf("sono arrivato fino a qua!\n");
    //printf("%s\n", argv[candidate_count+1]);
}


// Update ranks given a new vote //Done
bool vote(int rank, string name, int ranks[])
{

    for(int i = 0; i < candidate_count; i++){
        //checks if name is contained in candidates and if rank is valid (<= to the number of candidates)
        if((strcmp(name,candidates[i]) == 0) && rank <= candidate_count){/// if(strcmp(name,candidates[i]))
            ranks[rank] = i; // i == candidate name ---> candidate position inside the array called candidates.
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int i, j;
    for( i = 0; i < candidate_count; i++){
        for ( j = i+1; j < candidate_count; j++){
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int i, j;
    for( i = 0; i < candidate_count; i++){
        for(j = i; j < candidate_count; j++){
            if ( (j != i) && ( preferences[i][j] != preferences[j][i] ) ){
                if( preferences[i][j] > preferences[j][i] ){
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                }else if (  preferences[i][j] < preferences[j][i] ) {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                pair_count++;
            }
        }
    }
    return;
}



// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int i, j;
    for( i = 0; i < pair_count; i++){
        for ( j = i + 1; j < pair_count; j++){
            if( preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[i].winner][pairs[i].loser] ){
                swap( (pairs + j), (pairs + i));
            }
        }
    }

    return;
}
void swap(pair *a, pair *b ){
        pair tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
        return;
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int i, j, was_winner;
    for(i = 0; i < pair_count; i++){
        locked[pairs[i].winner][pairs[i].loser] = 1;
    }

    for(i = 0; i< pair_count; i++){
        if(i != j){
             if(has_cycle(pairs[i].winner, pairs[i].loser))
                locked[pairs[i].winner][pairs[i].loser] = 0;    
        }
        
      
    }
}

int has_cycle(int winner, int loser){
    for (int i = 0; i< pair_count; i++){
        if(winner = locked[i][winner]){
            winner = i;
            if (loser == winner){
                return 1;
            }
        }
    }
    return 0;
}
/* RECURSIVE VERSION
int has_cycle(int winner, int loser){
    if(winner == loser){
        return 1;
    }
    int i, j;
    for(i = 0; i < candidate_count; i++){
        for( j = 0; j < candidate_count; j++){
            if locked
        }
    }
    return false;
}*/

// Print the winner of the election
void print_winner(void)
{
    int i, j, src;
    for( i = 0; i < candidate_count; i++){
        src = 1;
        for( j = 0; j < candidate_count; j++){
            if( locked[j][i] == 1){
                src = 0;
                break;
            }
        }
        if(src){
            printf("%s", candidates[i]);
        }
    }
    return;
}
