#include <stdio.h>

typedef struct {
    int sentences;
    int words;
    int letts;
}coleman_types;

int main(){
    coleman_types a = {0};
    printf("s:%d\nw:%d\nl:%d\n", a.sentences, a.words, a.letts);
}