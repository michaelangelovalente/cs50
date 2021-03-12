#include <stdio.h>
#include <math.h>
typedef struct 
{
    int a;
    int b;
    int c;
}testing;


void print_my_data(int row, int col, testing data[4][5]){
    int i, j;
    for( i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            printf("[a:%02d b:%02d c:%02d] ", ((data[i] + j))->a, ((data[i] + j))->b, ((data[i] + j))->b  );
        }
        putchar('\n');
        putchar('\n');
    }
    //return data[1][1]; 
    return;
}

void avg_c(int i, int j, int row, int col, testing n[4][5]){
    testing tmp_val;
    tmp_val.a = 0;
    tmp_val.b = 0;
    tmp_val.c = 0;
    int x, y, x_bound = j + 1, y_bound = i + 1;
    float  ctr = 0;

    
    
    if(y_bound > row)
        y_bound = row;
    if(x_bound > col)
        x_bound = col;
    for( y = i - 1; y < y_bound; y++){
        if(y < 0)
            y = 0;
        for( x = j - 1 ; x < x_bound; x++){
            if(x < 0)
                x = 0;
                if( y != i || x != j ){
                    printf("[%02d - %02d - %02d] ", n[y][x].a, n[y][x].b, n[y][x].c );
                }else{
                    printf("[00 - 00 - 00] ");
                }
        }
        putchar('\n');
        putchar('\n');
    }
    for( y = i - 1; y < y_bound; y++){
        if(y < 0)
            y = 0;
        for( x = j - 1 ; x < x_bound; x++){
            if(x < 0)
                x = 0;
                if( y != i || x != j ){
                    tmp_val.a += n[y][x].a;
                    tmp_val.b += n[y][x].b;
                    tmp_val.c += n[y][x].c;
                    ctr += 1.0;
                }
                
        }
        putchar('\n');
    }
    printf("%f\n", ctr);
    tmp_val.a = round( tmp_val.a / ctr );
    tmp_val.b = round( tmp_val.b / ctr );
    tmp_val.c = round( tmp_val.c / ctr );
    for( y = i - 1; y < y_bound; y++){
        if(y < 0)
            y = 0;
        for( x = j - 1 ; x < x_bound; x++){
            if(x < 0)
                x = 0;
                if( y != i || x != j ){
                    printf("[%02d - %02d - %02d] ", n[y][x].a, n[y][x].b, n[y][x].c );
                }else{
                    printf("[%02d - %02d - %02d] ", tmp_val.a, tmp_val.b, tmp_val.c);
                }
                
        }
        putchar('\n');
        putchar('\n');
    }
    
    return;
}

int main(){
    testing n[4][5];
    //testing n2[4][5];
    //int **ptr_n = n;
    int i, j;
    //print_my_data(4,5, n);

    for( i = 0; i < 4; i++){
        for( j = 0; j < 5; j++){
            n[i][j].a = (i * 5) + j;
            n[i][j].b = (i * 5) + j;
            n[i][j].c = (i * 5) + j;
            //printf("[a:%02d b:%02d c:%02d] ", n[i][j].a, n[i][j].b, n[i][j].c );
        }
        //putchar('\n');
    }
   print_my_data(4,5, n);
   avg_c( 3, 0,4,5, n);
   

  return 0;  
}