#include "RandomNum.h"

std::mt19937 gen(static_cast<unsigned>(
    std::chrono::high_resolution_clock::now().time_since_epoch().count()
));

int myRand(int left, int right) {
    std::uniform_int_distribution<int> dist(left, right);
    return dist(gen);
}