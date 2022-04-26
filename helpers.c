#include "helpers.h"

// Convert image to grayscale
void	grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	BYTE	red;
	BYTE	green;
	BYTE	blue;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red = image[i][j].rgbtRed;
			green = image[i][j].rgbtGreen;
			blue = image[i][j].rgbtBlue;
			image[i][j].rgbtRed = (red + green + blue) / 3;
			image[i][j].rgbtGreen = (red + green + blue) / 3;
			image[i][j].rgbtBlue = (red + green + blue) / 3;
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
