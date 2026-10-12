#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <chrono>

std::string g[3] = {"策划", "美术", "研发"};

class Worker {
public:
    char m_id;
    int m_salary;
public:
    Worker(char id, int salary = 0) : m_id(id), m_salary(salary) {}
    void showifo() {
        std::cout << "员工：" << m_id 
                  << "\t\t工资：" << m_salary << std::endl; 
    }
};


static std::mt19937 gen(static_cast<unsigned>
    (std::chrono::high_resolution_clock::now().time_since_epoch().count()));

int base[3] = {10000, 12500, 15000};

int getSalary(int index) {
    // static std::random_device rd; //伪随机了
    // std::cout << "Seed_S: " << rd() << std::endl;
    // static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(base[index],20000);
    return dist(gen);
}

int getGroup() {
    // static std::random_device rd; //伪随机了
    // std::cout << "Seed_G: " << rd() << std::endl;
    // static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0,2);
    return dist(gen);
}


void setWorker(std::vector<Worker> &workers) {
    std::string s = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++) {
        workers.push_back(Worker(s[i]));
    }
}

void setGroup(std::vector<Worker> &workers, std::multimap<std::string, Worker> &group) {
    for(std::vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++) {
        int index = getGroup();
        (*it).m_salary = getSalary(index);
        group.insert(make_pair(g[index], (*it)));
    }
}

void printByGroup(std::multimap<std::string, Worker> &group) {
    for(int i = 0; i < 3; i++) {
        std::cout << g[i] << "组员工：" << std::endl;
        std::multimap<std::string, Worker>::iterator it = group.find(g[i]);
        int num = group.count(g[i]), cnt = 0;
        for(; it != group.end() && cnt < num; it++, cnt++) {
            (*it).second.showifo();
        }
    }
}

int main() {

    std::vector<Worker> workers;
    std::multimap<std::string, Worker> group;
 
    setWorker(workers);
    setGroup(workers, group);
    printByGroup(group);

    system("pause");

    return 0;
}