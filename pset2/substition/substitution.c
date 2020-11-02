#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE  100

int check_Key(char *key);
void substitution(char *target_str,int sizeTarget_str, char *key_str);

int main(int argc, char *argv[]){
    char usr_in[BUFFERSIZE] = {0};

    //-- arguments and key validity checks ------///
    if (argc != 2){
        printf("Invalid number of arguments.\nUsage: ./substitution <26-unique-char-key>.\n");
        return 1;
    }
    if (strlen(*(argv + 1)) != 26){
        printf("Invalid key, key must contain 26 characters.\nUsage: ./substitution <26-unique-char-key>.\n");
        return 1;
    }
    if(check_Key(*(argv + 1))){
        printf("Invalid key is not unique.\nUsage: ./substitution <26-unique-char-key>.\n");
        return 1;
    }
    //------------------------------------------------//

    //usr input and substitution
    printf("plaintext: ");
    fgets(usr_in, BUFFERSIZE, stdin );
    int lenOfUsrIn = strlen(usr_in);
    substitution(usr_in,lenOfUsrIn ,*(argv + 1));
    printf("ciphertext: %s", usr_in);
    

    return 0;
}





//takes a target string(target_str) and maps all characters using as a reference *key_str. 
//example: target_str == A 
void substitution(char *target_str,int sizeTarget_str, char *key_str){
    char map[26] = {0}; // key_str[0] == A ... key_str[len(key_str) - 1] = Z 
                        //--> we use the idx as a map from ASCII: idx == 0 is mapped to A == 'A' - 'A'(0) ... idx == 25 is mapped to 'z' - 'A';
    int i,j;
    //fills map with alphabet A ... Z
    for(i = 0; i < 26; i++){
        map[i] = *(key_str + i);
    }

    for(i = 0, j = 0; i < (sizeTarget_str - 1) ; i++){
        
        if( isalpha(*(target_str + i))){
            if( isupper(*(target_str + i))){
                *(target_str + i) =  toupper(map[*(target_str + i) - 'A']);    
            }
            if( islower(*(target_str + i))){
                *(target_str + i) = tolower( map[*(target_str + i) - 'a']);    
            }
            j++;
        }
    }
}

//check_Key takes a  26-character string and checks if the characters 
//inside it are unique and if it only contains alphabetical characters.
//returns Invalid key == 1; Valid Key == 0;
int check_Key(char *key){
    char unique_alpha[26] = {0};
    for(int i = 0; i < 26; i++){
        if(!isalpha(*(key + i))){
            return 1;
        }
        //lett - 'a'
        unique_alpha[toupper(*(key + i)) - 'A']++;
        if (unique_alpha[toupper(*(key + i)) - 'A'] > 1) {
            return 1;
        }
    }
    return 0;
}