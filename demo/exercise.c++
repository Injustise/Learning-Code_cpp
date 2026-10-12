#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

string generateTimeID() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *tm = localtime(&t);

    ostringstream oss;
    oss << put_time(tm, "%y%m%d");

    static unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    static mt19937 gen(seed);
    static uniform_int_distribution<int> dist(0,999);
    int randomPart = dist(gen);

    oss << setw(3) << setfill('0') << randomPart;

    return oss.str();
}

int main() {

    
    int num = 0;
    cin >> num;
    while(num--) {
        string s = generateTimeID();
        cout << s << endl;
    }
   

    return 0;
}