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
int int_convert(float p)
{
    if (p >= 255)
    {
        p = 255;
    }
    else
    {
        if (p < ((int)p + 0.5))
        {
            p = (int)p;
        }
        else
        {
            p = (int)p + 1;
        }
    }
    return p;
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRED;
            int blue = image[i][j].rgbtBLUE;
            int green = image[i][j].rgbtGREEN;
            float sred = 0.393 * red + 0.769 * green + 0.189 * blue;
            float sblue = 0.272 * red + 0.534 * green + 0.131 * blue;
            image[i][j].rgbtRED = int_convert(sred);
            image[i][j].rgbtBLUE = int_convert(sblue);
            image[i][j].rgbtGREEN = int_cinvert(sgreen);
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
