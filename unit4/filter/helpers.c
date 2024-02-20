#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // image[0][0] = rgbtBlue
    // take average of red green and blue to calculate the grey
    // set each rgb value equal to average

    // printf("height equals %i\n", height);
    // printf("width equals %i\n", width);
    // printf("Pixels = %i\n", height * width);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float average = (image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen) / 3.0;

            image[h][w].rgbtRed = (round(average));
            image[h][w].rgbtGreen = (round(average));
            image[h][w].rgbtBlue = (round(average));
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float sepiaRed = ((.393 * image[h][w].rgbtRed) + (.769 * image[h][w].rgbtGreen) + (.189 * image[h][w].rgbtBlue));
            float sepiaGreen = ((.349 * image[h][w].rgbtRed) + (.686 * image[h][w].rgbtGreen) + (.168 * image[h][w].rgbtBlue));
            float sepiaBlue = ((.272 * image[h][w].rgbtRed) + (.534 * image[h][w].rgbtGreen) + (.131 * image[h][w].rgbtBlue));

            if (sepiaRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = (round(sepiaRed));
            }

            if (sepiaGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = (round(sepiaGreen));
            }

            if (sepiaBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = (round(sepiaBlue));
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE temp;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width - (w + 1)];
            image[h][width - (w + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float averageRed = 0;
            float averageGreen = 0;
            float averageBlue = 0;
            // find the average rgb values of all of the squares around the pixel (include itself)

            // top row

            // bottom row

            // top left

            // top right

            // bottom left

            // bottom right

            // left column

            // right column

            // the rest
            if (h != 0 && w != 0 && h != (height - 1) && w != (width - 1))
            {
                averageRed = ((image[h][w].rgbtRed) + (image[h + 1][w + 1].rgbtRed) + (image[h - 1][h - 1].rgbtRed) +
                              (image[h + 1][w - 1].rgbtRed) + (image[h - 1][w + 1].rgbtRed) + (image[h + 1][w].rgbtRed) +
                              (image[h][w + 1].rgbtRed) + (image[h - 1][w].rgbtRed) + (image[h][w - 1].rgbtRed)) /
                             9;

                averageGreen = ((image[h][w].rgbtGreen) + (image[h + 1][w + 1].rgbtGreen) + (image[h - 1][h - 1].rgbtGreen) +
                                (image[h + 1][w - 1].rgbtGreen) + (image[h - 1][w + 1].rgbtGreen) + (image[h + 1][w].rgbtGreen) +
                                (image[h][w + 1].rgbtGreen) + (image[h - 1][w].rgbtGreen) + (image[h][w - 1].rgbtGreen)) /
                               9;

                averageBlue = ((image[h][w].rgbtBlue) + (image[h + 1][w + 1].rgbtBlue) + (image[h - 1][h - 1].rgbtBlue) +
                               (image[h + 1][w - 1].rgbtBlue) + (image[h - 1][w + 1].rgbtBlue) + (image[h + 1][w].rgbtBlue) +
                               (image[h][w + 1].rgbtBlue) + (image[h - 1][w].rgbtBlue) + (image[h][w - 1].rgbtBlue)) /
                              9;
            }

            if (averageRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = (round(averageRed));
            }

            if (averageGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = (round(averageGreen));
            }

            if (averageBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = (round(averageBlue));
            }
        }
    }
    return;
}
