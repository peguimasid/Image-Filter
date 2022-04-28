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
