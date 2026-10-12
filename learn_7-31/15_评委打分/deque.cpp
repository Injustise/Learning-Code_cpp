#include <iostream>
#include <string> 
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>

class Contestant {
public:
    int m_id;
    std::string m_name;
    double m_score;
public:
    Contestant() {}
    Contestant(int id, std::string name) : m_id(id), m_name(std::move(name)) {}
};

std::vector<Contestant> cs;

void init() {
    std::cout << "请输入参赛选手个数：" << std::endl;
    int n;
    std::cin >> n;

    std::string name;
    Contestant player;
    for(int i = 1; i <= n; i++) {
        std::cout << "请输入第 " << i << " 名选手的姓名：" << std::endl;
        std::cin >> name;
        player = Contestant(i, name);
        cs.push_back(player);
    }
}

int getScore() {
    static std::mt19937 gen(static_cast<unsigned>
        (std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    // static std::random_device rd; //伪随机了
    // static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(60, 100);
    return dist(gen);
}

double getAverage(const std::deque<int> &TotalScore) {
    double sum = 0.0;
    for(std::deque<int>::const_iterator it = TotalScore.begin(); it != TotalScore.end(); it++) {
        sum += (*it);
    }
    return sum / (TotalScore.size() * 1.0);
}

void work() {
    std::deque<int> TotalScore;

    std::cout << "评委打分中..." << std::endl;
    for(std::vector<Contestant>::iterator it = cs.begin(); it != cs.end(); it++) {
        // std::cout << "请依次输入第 " << (*it).m_id << " 名选手：" << (*it).m_name << "的得分情况：" << std::endl;
        for(int i = 1; i <= 10 ; i++) {
            TotalScore.push_back(getScore());
        }

        std::sort(TotalScore.begin(), TotalScore.end());
        TotalScore.pop_front();
        TotalScore.pop_back();

        (*it).m_score = getAverage(TotalScore);
        TotalScore.clear();
    }
}

void rank() {
    sort(cs.begin(), cs.end(),
        [](const Contestant &a, const Contestant &b) { //Lambda
            return a.m_score > b.m_score;
        });
}

void print() {
    std::cout << "得分排行榜：" << std::endl;
    int rank = 0;
    for(std::vector<Contestant>::const_iterator it = cs.begin(); it != cs.end(); it++) {
        std::cout << "第 " << ++rank << " 名：" << (*it).m_name
                  << "\t得分：" << (*it).m_score << std::endl;
    }
}

int main() {

    init();
    work();
    rank();
    print();

    system("pause");

    return 0;
}