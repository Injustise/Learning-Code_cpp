#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name; //姓名
    int age; //年龄指针
public:
    Person(string n, int a) : name(move(n)), age(a) {} //初始化列表
    string get_name() {
        return name;
    }
    int get_age() {
        return age;
    }
};

void test() {
    Person p("Alice",18);
    cout << "p 的姓名是：" << p.get_name() << "，年龄是：" << p.get_age() << endl;
}

int main() {

    test();

    system("pause");

    return 0;
}