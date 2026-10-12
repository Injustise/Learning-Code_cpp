#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name; //姓名
    int *age; //年龄指针
public:
    Person(string n, int a) { //构造函数
        name = n;
        age = new int (a); //创建值为 a 的堆区内存，并返回其指针
        //如果有成员属性在堆区创建内存空间，一定要用自己写的深拷贝构造函数，防止浅拷贝带来报错（堆区内存重复释放）
        cout << "Person 的构造函数" << endl; 
    }
    ~Person() { //析构函数，将创建的堆区内存释放
        if(age != nullptr) {
            delete age; //释放 age 所指的堆区内存
            age = nullptr; 
        }
        cout << "Person 的析构函数" << endl;
    }
    Person(const Person &p) { //拷贝构造函数
        name = p.name;
        //age = p.age //编译器默认的拷贝构造函数（浅拷贝：简单的赋值拷贝操作）
        age = new int (*p.age); //（深拷贝：在堆区重新创建内存空间，进行拷贝操作）
        cout << "Person 的拷贝构造函数" << endl;
    }
    string get_name() {
        return name;
    }
    int get_age() {
        return *age;
    }
};

void test() {
    Person p1("John", 18);
    Person p2(p1);

    cout << "p1 的姓名是：" << p1.get_name() << "，年龄是：" << p1.get_age() << endl;
    cout << "p2 的姓名是：" << p2.get_name() << "，年龄是：" << p2.get_age() << endl;

}

int main() {

    test();

    system("pause");

    return 0;
}