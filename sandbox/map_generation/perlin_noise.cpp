#include "perlin_noise.h"
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

PerlinNoise::PerlinNoise(unsigned int seed) {
    permutation.resize(256);

    // Populate vector will values from 0 to 255
    std::iota(permutation.begin(), permutation.end(), 0);

    // Initialize a random engine with provided seed
    std::default_random_engine engine(seed);

    // Shuffle the values above
    std::shuffle(permutation.begin(), permutation.end(), engine);

    // Duplicate the vector
    permutation.insert(permutation.end(), permutation.begin(), permutation.end());
}

PerlinNoise::~PerlinNoise() {
  
}

double PerlinNoise::noise(double x, double y, double z) {
  	// Find the unit cube that contains the point
  	int X = (int) floor(x) & 255;
  	int Y = (int) floor(y) & 255;
  	int Z = (int) floor(z) & 255;

  	// Find relative x, y,z of point in cube
  	x -= floor(x);
  	y -= floor(y);
  	z -= floor(z);

  	// Compute fade curves for each of x, y, z
  	double u = fade(x);
  	double v = fade(y);
  	double w = fade(z);

  	// Hash coordinates of the 8 cube corners
  	int A = permutation[X] + Y;
  	int AA = permutation[A] + Z;
  	int AB = permutation[A + 1] + Z;
  	int B = permutation[X + 1] + Y;
  	int BA = permutation[B] + Z;
  	int BB = permutation[B + 1] + Z;

  	// Add blended results from 8 corners of cube
  	double res = lerp(w, lerp(v, lerp(u, grad(permutation[AA], x, y, z), grad(permutation[BA], x-1, y, z)), lerp(u, grad(permutation[AB], x, y-1, z), grad(permutation[BB], x-1, y-1, z))),	lerp(v, lerp(u, grad(permutation[AA+1], x, y, z-1), grad(permutation[BA+1], x-1, y, z-1)), lerp(u, grad(permutation[AB+1], x, y-1, z-1),	grad(permutation[BB+1], x-1, y-1, z-1))));
  	return (res + 1.0)/2.0;
}

double PerlinNoise::fade(double t) {
  	return t * t * t * (t * (t * 6 - 15) + 10);
}

double PerlinNoise::lerp(double t, double a, double b) {
  	return a + t * (b - a);
}

double PerlinNoise::grad(int hash, double x, double y, double z) {
  	int h = hash & 15;
  	// Convert lower 4 bits of hash inot 12 gradient directions
  	double u = h < 8 ? x : y,
  		   v = h < 4 ? y : h == 12 || h == 14 ? x : z;
  	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}
