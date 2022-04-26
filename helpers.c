#include "helpers.h"

// Convert image to grayscale
void	grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	BYTE	red;
	BYTE	green;
	BYTE	blue;
	BYTE	grayscale;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red = image[i][j].rgbtRed;
			green = image[i][j].rgbtGreen;
			blue = image[i][j].rgbtBlue;
			grayscale = (0.299 * red) + (0.587 * green) + (0.114 * blue);
			image[i][j].rgbtRed = grayscale;
			image[i][j].rgbtGreen = grayscale;
			image[i][j].rgbtBlue = grayscale;
		}
	}
}

// Convert image to sepia
void	sepia(int height, int width, RGBTRIPLE image[height][width])
{
	return ;
}

// Reflect image horizontally
void	reflect(int height, int width, RGBTRIPLE image[height][width])
{
	return ;
}

// Blur image
void	blur(int height, int width, RGBTRIPLE image[height][width])
{
	return ;
}
