#include <iostream>
#include <string>
using namespace std;

class Person {
    friend ostream & operator<<(ostream &cout, const Person &p);
private:
    string m_name;
    int *m_age; 
public:
    Person(string name, int age) {
        m_name = move(name);
        m_age = new int (age); //m_age 在堆区开辟内存
    }
    ~Person() { //释放堆区内存
        if(m_age != nullptr) {
            delete m_age; //堆区内存要手动释放，防止内存泄漏
            m_age = nullptr;
        }
    }
    void operator=(const Person &p) {
        m_name = p.m_name;
        //m_age = p.m_age //错误，默认的赋值运算符为浅拷贝，而浅拷贝对于堆区内存会引发重复释放，导致报错
        m_age = new int (*p.m_age); //深拷贝
    }
};

ostream & operator<<(ostream &cout, const Person &p) {
    cout << p.m_name << ' ' << *p.m_age;
    return cout;
}

void test() {
    Person p1("John",20);
    Person p2("Alice",18);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    p1 = p2;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
}

int main() {

    test();

    system("pause");

    return 0;
}