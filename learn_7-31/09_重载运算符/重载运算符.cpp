#include <iostream>
#include <string>
using namespace std;

class Person {
    friend ostream & operator<<(ostream &cout, const Person &p);
private:
    string m_name;
    int m_age;
public:
    Person(string name, int age) : m_name(move(name)), m_age(age) {}
    Person & operator+(int Add_age) { //重载 + （加号）运算符
        m_age += Add_age;
        return *this;
    }
    Person & operator++() { //重载前置 ++ （递增）运算符
        m_age++;
        return *this; 
    }
    Person operator++(int) { //重载后置 ++ （递增）运算符
        Person temp = *this;
        m_age++;
        return temp;
    }
};

//若返回 ostream 值类型，则生成临时对象（cout'）引发拷贝，但流不可拷贝，故报错
ostream & operator<<(ostream &cout, const Person &p) { //重载 << （左移）运算符，实现输出自定义类型
    cout << p.m_name << " 的年龄为 " << p.m_age;
    return cout; //返回 cout ，实现链式调用
}

void test() {
    cout << "test:" << endl;
    Person  p("John",18);
    p = p + 4;
    cout << p << endl;
}

void test01() {
    cout << "test01:" << endl;
    Person p("John",18);
    cout << p << endl; // (cout, p) 用的是重载的 << ，然后再返回 cout 
                       // (cout, endl) 用的是 iostream 内置的 <<
}

void test02() {
    cout << "test02:" << endl;
    Person p("John",18);
    cout << ++(++p) << endl;
    cout << p++ << endl;
    cout << p << endl;
    
}

int main() {

    test();

    test01();

    test02();

    system("pause");

    return 0;
}