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
	BYTE	red;
	BYTE	green;
	BYTE	blue;
	int		tr;
	int		tg;
	int		tb;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red = image[i][j].rgbtRed;
			green = image[i][j].rgbtGreen;
			blue = image[i][j].rgbtBlue;
			tr = (0.393 * red) + (0.769 * green) + (0.189 * blue);
			tg = (0.349 * red) + (0.686 * green) + (0.168 * blue);
			tb = (0.272 * red) + (0.534 * green) + (0.131 * blue);
			if (tr > 255)
			{
				image[i][j].rgbtRed = 255;
			}
			else
			{
				image[i][j].rgbtRed = tr;
			}
			if (tg > 255)
			{
				image[i][j].rgbtGreen = 255;
			}
			else
			{
				image[i][j].rgbtGreen = tg;
			}
			if (tb > 255)
			{
				image[i][j].rgbtBlue = 255;
			}
			else
			{
				image[i][j].rgbtBlue = tb;
			}
		}
	}
}

// Reflect image horizontally
void	reflect(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = width / 2; j >= 0; j--)
		{
			image[i][width - j + 1] = image[i][j];
		}
	}
}

// Blur image
void	blur(int height, int width, RGBTRIPLE image[height][width])
{
	return ;
}
