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
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
        for (int n = 0; n < width; n++)
        {
            image[i][n] = temp[i][width - 1 - n];
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sr = 0, sb = 0, sg = 0, count = 0;
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }
                    count ++;
                    sr += temp[i + r][j + c].rgbtRed;
                    sb += temp[i + r][j + c].rgbtBlue;
                    sg += temp[i + r][j + c].rgbtGreen;
                    image[i][j].rgbtRed = int_convert(sr / count);
                    image[i][j].rgbtBlue = int_convert(sb / count);
                    image[i][j].rgbtGreen = int_convert(sg / count);
                }
            }
        }
    }
    return;

}

