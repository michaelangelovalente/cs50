#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, tmp;
    for (i = 0; i < height; i++ ){
        for( j = 0; j < width; j++){
            tmp = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);//image[height][width];
            image[i][j].rgbtRed = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtBlue = tmp;

        }


    }
    return;
}

void swap(uint8_t *a, uint8_t *b){
    uint8_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    int tmp = width /2;

    for (i = 0; i < height; i++){
        for(j = 0 ; j < tmp; j++){
            swap(&image[i][j].rgbtRed, &image[i][width - (j + 1)].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width - (j + 1)].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][width - (j + 1)].rgbtBlue);
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE  tmp_image[height][width];
    int i, j;
    float count = 0.0;


    for( i = 0; i < height; i++){
        for( j = 0; j < width; j++){
            //4 angles
            //top 
            if(i == 0){
                count = 4;
                //top left 
                if( j == 0){
                    //count = 4;
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j].rgbtBlue))/ count);

                }else if(j == width -1){ //top right
                    //count = 4;
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i+1][j - 1].rgbtRed + image[i+1][j].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i+1][j - 1].rgbtGreen + image[i+1][j].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i+1][j - 1].rgbtBlue + image[i+1][j].rgbtBlue))/ count);

                }else{//just top
                    count = 6;
                    tmp_image[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j+1].rgbtRed + image[i + 1][j - 1].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i][j+1].rgbtGreen + image[i + 1][j - 1].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i][j+1].rgbtBlue + image[i + 1][j - 1].rgbtBlue))/ count);
                }
            }   

            //bottom
            if(i == height -1 ){
                count = 3;
                //bottom left
                if(j == 0){
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue))/ count);
                    
                }else if ( j == width - 1){//botttom right
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i-1][j -1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i-1][j -1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i-1][j -1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue))/ count);

                }else{//just bottom
                    count = 5;
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue))/ count);
                }
            }
            
            //sides
            if(i>0 && i < height - 1){
                count = 6;
                if( j == 0 ){ //left-side
                    tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j+1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j+1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j+1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue))/ count);

                }else if( j == width - 1){//right-side
                    tmp_image[i][j].rgbtRed = round((( tmp_image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j-1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed))/ count);
                    tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j-1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen))/ count);
                    tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j-1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue))/ count);
                }
            }

            //center
            if( (i > 0 && i < height - 1) && ( j > 0 && j < width - 1)){
                count = 9;
                tmp_image[i][j].rgbtRed = round((( image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j-1].rgbtRed))/ count);
                tmp_image[i][j].rgbtGreen = round((( image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j-1].rgbtGreen))/ count);
                tmp_image[i][j].rgbtBlue = round((( image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j-1].rgbtBlue))/ count);
            }
        }
    }
    for( i = 0; i < height; i++){
        for( j = 0; j < width; j++){
            image[i][j] = tmp_image[i][j];
        }
    }
    return;
}






// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{   
    
    RGBTRIPLE tmp_image[height][width];
    
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
        };

    int Gy[3][3]= {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
        };

    int r = 0, c = 0;
    int i, j;
    int red_gx, green_gx, blue_gx;
    int red_gy, green_gy, blue_gy;


    for( i = 0; i < height; i++){
        for(j = 0; j < width; j++){

            int r_Coords[] = {i - 1, i, i + 1};
            int c_Coords[] = {j - 1, j, j + 1}; 
            red_gx = green_gx = blue_gx = red_gy = green_gy = blue_gy = 0;

            for(r = 0; r < 3; r++ ){
                for(c = 0; c < 3; c++){

                    if( r_Coords[r] >= 0 && c_Coords[c] >= 0 && r_Coords[r] < height && c_Coords[c] < width ){

                        red_gx += (image[r_Coords[r]][c_Coords[c]].rgbtRed * Gx[r][c]);
                        green_gx += (image[r_Coords[r]][c_Coords[c]].rgbtGreen * Gx[r][c]);
                        blue_gx += (image[r_Coords[r]][c_Coords[c]].rgbtBlue * Gx[r][c]);

                        
                        red_gy += (image[r_Coords[r]][c_Coords[c]].rgbtRed * Gy[r][c]);
                        green_gy += (image[r_Coords[r]][c_Coords[c]].rgbtGreen * Gy[r][c]);
                        blue_gy += (image[r_Coords[r]][c_Coords[c]].rgbtBlue * Gy[r][c]);

                    }

                }
            }

            red_gx = round( sqrt( ( red_gx * red_gx ) + ( red_gy * red_gy ) ) );
            green_gx = round( sqrt( ( green_gx * green_gx ) + ( green_gy * green_gy ) ) );
            blue_gx = round( sqrt( ( blue_gx * blue_gx ) + ( blue_gy * blue_gy ) ) );


            tmp_image[i][j].rgbtRed =  red_gx > 255 ? 255 : red_gx;
            tmp_image[i][j].rgbtGreen = green_gx > 255 ? 255 : green_gx;
            tmp_image[i][j].rgbtBlue = blue_gx > 255 ? 255 : blue_gx;
        }
    }


    for( i = 0; i < height; i ++){
        for( j = 0; j < width; j++){
            image[i][j].rgbtRed = tmp_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp_image[i][j].rgbtBlue;
        }
    }


    return;
}