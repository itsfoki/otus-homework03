
#include "getRandomNumber.h"

unsigned int getRandomNumber(unsigned int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist{0, max}; 
    return dist(rng);
}