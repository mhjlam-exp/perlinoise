#include <cmath>
#include <ctime>
#include "ppm.h"
#include "perlin.h"

int main()
{
	// Define the size of the image
	unsigned int width = 512;
	unsigned int height = 512;

	// Create an empty PPM image
	ppm image(width, height);

	// Create a PerlinNoise object with the reference permutation vector
	PerlinNoise pn((unsigned int)time(0));

	// Visit every pixel of the image and assign a color generated with Perlin noise
	for (unsigned int i = 0, kk = 0; i < height; ++i) // y
	{
		for (unsigned int j = 0; j < width; ++j, ++kk) // x
		{
			double x = (double)j / ((double)width);
			double y = (double)i / ((double)height);

			// Typical Perlin noise
			double n = pn.noise(10 * x, 10 * y, 0.8);

			// Map the values to the [0, 255] interval, for simplicity we use gray tones
			image.r[kk] = floor(255 * n);
			image.g[kk] = floor(255 * n);
			image.b[kk] = floor(255 * n);
		}
	}

	// Save the image in a binary PPM file
	image.write("PerlinDemo_00.ppm");

	return 0;
}
