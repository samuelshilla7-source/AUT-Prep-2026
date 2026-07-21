#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0;

            average = (int)round(average);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            sepiaRed = (int)round(sepiaRed);
            sepiaGreen = (int)round(sepiaGreen);
            sepiaBlue = (int)round(sepiaBlue);

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        int K = width/2;
        for(int j = 0; j < K; j++)
        {
            RGBTRIPLE L;
            L = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = L;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
             copy[i][j] = image[i][j];
        }
    }
   
    for(int i =0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;
            int counter = 0;

            for(int di = -1; di <= 1; di++)
            {
                if(i + di >= 0 && i + di < height)
                {
                    for(int dj = -1; dj <= 1; dj++)
                    {
                        if(j + dj >= 0 && j + dj < width)
                        {
                            sumR += copy[i+di][j+dj].rgbtRed;
                            sumG += copy[i+di][j+dj].rgbtGreen;
                            sumB += copy[i+di][j+dj].rgbtBlue;

                            counter += 1;                    
                        }
                    }
                }
            }
            int averageR = sumR/counter;
            int averageG = sumG/counter;
            int averageB = sumB/counter;

            image[i][j].rgbtRed = averageR;
            image[i][j].rgbtGreen = averageG;
            image[i][j].rgbtBlue = averageB;
        }
    }
    return;
}

