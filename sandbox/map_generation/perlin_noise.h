#include <vector>

#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H

class PerlinNoise {
    std::vector<int> permutation;

  public:
    PerlinNoise(unsigned int seed);
    ~PerlinNoise();

    double noise(double x, double y, double z);

  private:
    double fade(double t);
    double lerp(double t, double a, double b);
    double grad(int hash, double x, double y, double z);
};

#endif
