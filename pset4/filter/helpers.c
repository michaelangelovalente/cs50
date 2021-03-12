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
    int i, j, r, c, count;
    int red, green, blue;

    for( i = 0; i < height; i++){
        for( j = 0; j < width; j++){
            int r_Coord[] = { i-1, i, i+1};
            int c_Coord[] = {j-i, j, j+1};
            count = 0;

            for(r = 0; r < 3; r++){
                for( c = 0; c < 3; c++){

                    if(r_Coord[r] >= 0 && c_Coord[c] >= 0 && r_Coord[r] < height && c_Coord[c] < width){

                        red += image[r_Coord[r]][c_Coord[c]].rgbtRed;
                        green += image[r_Coord[r]][c_Coord[c]].rgbtGreen;
                        blue += image[r_Coord[r]][c_Coord[c]].rgbtBlue;
                        count++;
                    }

                }
            }
            red = red/count;
            green = green/count;
            blue = blue/count;
            
            tmp_image[i][j].rgbtRed = (red) > 255? 255 : red;
            tmp_image[i][j].rgbtGreen = (green) > 255? 255 : green;
            tmp_image[i][j].rgbtBlue = (blue) > 255? 255 : blue;

        }
    }

    for( i = 0; i < height; i++){
        for( j = 0; j < width; j++){
            image[i][j].rgbtRed = tmp_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp_image[i][j].rgbtBlue;
        }
    }
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