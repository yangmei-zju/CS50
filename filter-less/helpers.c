#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
             float average;
             average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
             if ( average < ((int)average + 0.5))
             {
                average = (int)average;
             }
             else
             {
                average = (int)average + 1;
             }
             image[i][j].rgbtBlue = average;
             image[i][j].rgbtGreen = average;
             image[i][j].rgbtRed = average;
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
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            float sred = 0.393 * red + 0.769 * green + 0.189 * blue;
            float sblue = 0.272 * red + 0.534 * green + 0.131 * blue;
            float sgreen = 0.349 * red + 0.686 * green + 0.168 * blue;
            image[i][j].rgbtRed = int_convert(sred);
            image[i][j].rgbtBlue = int_convert(sblue);
            image[i][j].rgbtGreen = int_convert(sgreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image[i][width - j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    image[0][0].rgbtRed =int_convert((temp[0][0].rgbtRed + temp[0][1].rgbtRed + temp[1][0].rgbtRed + temp[1][1].rgbtRed) / 4.0);
    image[0][0].rgbtBlue =int_convert((temp[0][0].rgbtBlue + temp[0][1].rgbtBlue + temp[1][0].rgbtBlue + temp[1][1].rgbtBlue) / 4.0);
    image[0][0].rgbtRed =int_convert((temp[0][0].rgbtGreen + temp[0][1].rgbtGreen + temp[1][0].rgbtGreen + temp[1][1].rgbtGreen) / 4.0);
    image[0][width - 1].rgbtRed =int_convert((temp[0][width - 1].rgbtRed + temp[0][width - 2].rgbtRed + temp[1][width - 1].rgbtRed + temp[1][width - 2].rgbtRed) / 4.0);
    image[0][width - 1].rgbtBlue =int_convert((temp[0][width - 1].rgbtBlue + temp[0][width - 2].rgbtBlue + temp[1][width - 1].rgbtBlue + temp[1][width - 2].rgbtBlue) / 4.0);
    image[0][width - 1].rgbtRed =int_convert((temp[0][width - 1].rgbtGreen + temp[0][width - 2].rgbtGreen + temp[1][width - 1].rgbtGreen + temp[1][width - 2].rgbtGreen) / 4.0);
    image[height - 1][0].rgbtRed =int_convert((temp[height - 1][0].rgbtRed + temp[height - 1][1].rgbtRed + temp[height - 2][0].rgbtRed + temp[height - 2][1].rgbtRed) / 4.0);
    image[height - 1][0].rgbtBlue =int_convert((temp[height - 1][0].rgbtBlue + temp[height - 1][1].rgbtBlue + temp[height - 2][0].rgbtBlue + temp[height - 2][1].rgbtBlue) / 4.0);
    image[height - 1][0].rgbtRed =int_convert((temp[height - 1][0].rgbtGreen + temp[height - 1][1].rgbtGreen + temp[height - 2][0].rgbtGreen + temp[height - 2][1].rgbtGreen) / 4.0);
    image[height - 1][width - 1].rgbtRed =int_convert((temp[height - 1][width - 1].rgbtRed + temp[height -1 ][width - 2].rgbtRed + temp[height - 2][width - 1].rgbtRed + temp[height - 2][width - 2].rgbtRed) / 4.0);
    image[height - 1][width - 1].rgbtBlue =int_convert((temp[height - 1][width - 1].rgbtBlue + temp[height -1][width - 2].rgbtBlue + temp[height - 2][width - 1].rgbtBlue + temp[height - 2][width - 2].rgbtBlue) / 4.0);
    image[height - 1][width - ].rgbtRed =int_convert((temp[height - 1][width - 1].rgbtGreen + temp[height - 1][width - 2].rgbtGreen + temp[height - 2][width - 1].rgbtGreen + temp[height - 2][width - 2].rgbtGreen) / 4.0);
    for( j = 1; j < width - 1; j++)
    {
        image[0][j] = int_convert(())
    }
    return;

}

