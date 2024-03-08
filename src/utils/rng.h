#include <random>

double randomnumber()
{
    // Making rng static ensures that it stays the same
    // Between different invocations of the function
    static std::default_random_engine rng;

    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int randomint(int min, int max)
{
    static std::default_random_engine rng;

    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}