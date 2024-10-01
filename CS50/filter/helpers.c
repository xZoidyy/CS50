#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int value = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);

            image[i][j].rgbtBlue = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtRed = value;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaB = 0;
    int sepiaG = 0;
    int sepiaR = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // secure that colors are not greater than 255
            if (sepiaR > 255) sepiaR = 255;
            if (sepiaG > 255) sepiaG = 255;
            if (sepiaB > 255) sepiaB = 255;

            image[i][j].rgbtRed = sepiaR;
            image[i][j].rgbtGreen = sepiaG;
            image[i][j].rgbtBlue = sepiaB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int up = round(width/2.0);
    int tempB = 0;
    int tempG = 0;
    int tempR = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < up; j++)
        {   
            // SWAPS

            // BLUE
            tempB = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            image[i][width - j].rgbtBlue = tempB;

            //GREEN
            tempG = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][width - j].rgbtGreen = tempG;

            //RED
            tempR = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j].rgbtRed;
            image[i][width - j].rgbtRed = tempR;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   

    //make copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //blurring
    for (int i = 0; i < height; i++)
    {  
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int blurR = 0;
            int blurG = 0;
            int blurB = 0;
            int k1 = 0;
            int k2 = 0;
            int l1 = 0;
            int l2 = 0;
            
            // i bounderies
            if (i - 1 >= 0)
            {
                k1 = i - 1;
            }
            if (i - 1 < 0)
            {
                k1 = i;
            }
            if (i + 1 < height)
            {
                k2 = i + 1;
            }
            if (i + 1 >= height)
            {
                k2 = i;
            }
            // j bounderies
            if (j - 1 >= 0)
            {
                l1 = j - 1;
            }
            if (j - 1 < 0)
            {
                l1 = j;
            }
            if (j + 1 < width)
            {
                l2 = j + 1;
            }
            if (j + 1 >= width)
            {
                l2 = j;
            }

            // 3x3 box for blurring
            for (int m = k1; m < k2; m++)
            {
                for (int n = l1; n < l2; n++)
                {
                    if (m == i && n == j)
                    {

                    }
                    else
                    {
                        blurB += copy[m][n].rgbtBlue;
                        blurG += copy[m][n].rgbtGreen;
                        blurR += copy[m][n].rgbtRed;
                        count++;
                    }
                }
            }

            image[i][j].rgbtBlue = round(blurB/(float)count);
            image[i][j].rgbtGreen = round(blurG/(float)count);
            image[i][j].rgbtRed = round(blurR/(float)count);
        }
    }

    return;
}
