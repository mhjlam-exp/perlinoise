#pragma once
#include <vector>

class PerlinNoise
{
private:
	std::vector<int> p;	// permutations
	
public:
	PerlinNoise(); // initialize with reference permutation table
	PerlinNoise(unsigned int seed); // generate permutation table based on seed
	double noise(double x, double y, double z); // obtain noise value (z is optional)
	
private:
	double fade(double t);
	double lerp(double t, double a, double b);
	double grad(int hash, double x, double y, double z);
};
