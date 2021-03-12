#include <stdio.h>
#include <math.h>

int Sobel_root(int a, int b){
    double tmp;
    tmp = sqrt((double)((a*a) + (b*b)));
    if(tmp>= 255)
        return 255;
    tmp = round(tmp);
    return (int)tmp;
}


int main(void){
    int a, b, c, red, green, blue;
     a = (red = red/count) > 255? 255 : red;
        b = (green = green/count) > 255? 255 : green;
            c = (blue = blue/count) > 255? 255 : blue;
    
    
}