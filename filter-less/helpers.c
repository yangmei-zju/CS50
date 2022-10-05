#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int i = 0; j < width; j ++)
        {
             float average;
             average = (image[i][j].rgbtBLUE + image[i][j].rgbtGREEN + image[i][j].rgbtRED) / 3.0;
             if ( average < ((int)average + 0.5))
             {
                average = (int)average;
             }
             else
             {
                average = (int)average + 1;
             }
             image[i][j].rgbtBLUE = average;
             image[i][j].rgbtGREEN = average;
             image[i][j].rgbtRED = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRED;
            int blue = image[i][j].rgbtBLUE;
            int green = image[i][j].rgbtGREEN;
            


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
