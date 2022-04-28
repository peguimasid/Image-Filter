#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void	grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	float	rgbGray;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			rgbGray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen
						+ image[i][j].rgbtBlue) / 3.00);
			image[i][j]
				.rgbtRed = rgbGray;
			image[i][j].rgbtGreen = rgbGray;
			image[i][j].rgbtBlue = rgbGray;
		}
	}
}

int	limit(int RGB)
{
	if (RGB > 255)
	{
		RGB = 255;
	}
	return (RGB);
}

// Convert image to sepia
void	sepia(int height, int width, RGBTRIPLE image[height][width])
{
	BYTE	r;
	BYTE	g;
	BYTE	b;
	int		sepiaRed;
	int		sepiaGreen;
	int		sepiaBlue;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			r = image[i][j].rgbtRed;
			g = image[i][j].rgbtGreen;
			b = image[i][j].rgbtBlue;
			sepiaRed = limit(round(0.393 * r + 0.769 * g + 0.189 * b));
			sepiaGreen = limit(round(0.349 * r + 0.686 * g + 0.168 * b));
			sepiaBlue = limit(round(0.272 * r + 0.534 * g + 0.131 * b));
			image[i][j].rgbtRed = sepiaRed;
			image[i][j].rgbtGreen = sepiaGreen;
			image[i][j].rgbtBlue = sepiaBlue;
		}
	}
}

// Reflect image horizontally
void	reflect(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE	copy[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			copy[i][j] = image[i][j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][width - j - 1] = copy[i][j];
		}
	}
}

int	getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width],
		int color_position)
{
	float	counter;
	int		sum;

	counter = 0;
	sum = 0;
	for (int k = i - 1; k < (i + 2); k++)
	{
		for (int l = j - 1; l < (j + 2); l++)
		{
			if (k < 0 || l < 0 || k >= height || l >= width)
				continue ;
			if (color_position == 0)
			{
				sum += image[k][l].rgbtRed;
			}
			if (color_position == 1)
			{
				sum += image[k][l].rgbtGreen;
			}
			if (color_position == 2)
			{
				sum += image[k][l].rgbtBlue;
			}
			counter++;
		}
	}
	return (round(sum / counter));
}

// Blur image
void	blur(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE	copy[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			copy[i][j] = image[i][j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
			image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 1);
			image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 2);
		}
	}
}
