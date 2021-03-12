#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2 ){
        printf("usage: ./recover image\n");
        return 1;

    }
    
    FILE *file = fopen( argv[1], "r");

    if(!file){
        printf("Error: not a valid file.\n");
        return 1;
    }
    
    typedef uint8_t BYTE;
    BYTE block[BLOCK_SIZE];
    size_t bytes_read;
    int i = 0;
    bool first_jpeg = false;
    bool read_curr_jpeg = false;
    
    while(1){
        bytes_read = fread(block, sizeof(BYTE), BLOCK_SIZE, file);
        if( bytes_read == 0){
            //EOF
            break;
        }
        //Check first four bytes --> beginning of a jpeg file
        if(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0 ){ 
            i++;
            if(!first_jpeg)
                first_jpeg = true;
        }
    }
    
    return 0;
}   
