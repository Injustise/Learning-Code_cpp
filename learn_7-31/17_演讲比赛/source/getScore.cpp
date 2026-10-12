#include "getScore.h"

double getScore() {
    std::deque<int> score;
    for(int i = 1; i <= 10; i++) score.push_back(myRand(60,100));
    std::sort(score.begin(), score.end());
    score.pop_front();
    score.pop_back();
    return static_cast<double>(std::accumulate(score.begin(), score.end(), 0)) / (score.size() * 1.0);
}