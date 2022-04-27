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
	RGBTRIPLE	copy[height][width];
	RGBTRIPLE	u;
	RGBTRIPLE	d;
	RGBTRIPLE	l;
	RGBTRIPLE	r;
	RGBTRIPLE	lu;
	RGBTRIPLE	ru;
	RGBTRIPLE	ld;
	RGBTRIPLE	rd;
	int			red;
	int			green;
	int			blue;

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
			// Up pixel
			u = copy[i - 1][j];
			// Down pixel
			d = copy[i + 1][j];
			// Reft pixel
			l = copy[i][j - 1];
			// Right pixel
			r = copy[i][j + 1];
			// Left upper pixel
			lu = copy[i - 1][j - 1];
			// Right upper pixel
			ru = copy[i - 1][j + 1];
			// Left down pixel
			ld = copy[i + 1][j - 1];
			// Right down pixel
			rd = copy[i + 1][j + 1];
			red = (u.rgbtRed + d.rgbtRed + l.rgbtRed + r.rgbtRed + lu.rgbtRed
					+ ru.rgbtRed + ld.rgbtRed + rd.rgbtRed) / 9;
			green = (u.rgbtGreen + d.rgbtGreen + l.rgbtGreen + r.rgbtGreen
					+ lu.rgbtGreen + ru.rgbtGreen + ld.rgbtGreen + rd.rgbtGreen)
				/ 9;
			blue = (u.rgbtBlue + d.rgbtBlue + l.rgbtBlue + r.rgbtBlue
					+ lu.rgbtBlue + ru.rgbtBlue + ld.rgbtBlue + rd.rgbtBlue)
				/ 9;
			image[i][j].rgbtRed = red;
			image[i][j].rgbtGreen = green;
			image[i][j].rgbtBlue = blue;
		}
	}
}
