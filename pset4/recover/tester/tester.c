#include <stdio.h>
int main(int argc, char *argv[]){
    if( argc != 2)
        return 1;
    
    FILE *file = fopen(argv[1], "r");

    if(!file)
        return 1;

    unsigned char bytes[100];
    
    char string[100];
    
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && ((bytes[3] & 0xf0) == 0xe0) ){
        fread(bytes, 100, 1, file);    
        printf("might be jpeg\n");

    }
}
    //OPEN memory card
    //Repeat until end of card:
    //  Read 512 bytes into a buffer
    //  If start of new JPEG
    //      If first JPEG
    //          write jpeg
    //          ...
    //      Else
    //          ...
    //  Else
    //      If already found JPEG
    //          ...
