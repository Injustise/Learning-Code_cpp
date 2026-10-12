#include <iostream>
#include <string>

using namespace std;

class Animal {
protected: 
    string m_class;
public:
    Animal(string name) : m_class(move(name)) {} 
    virtual void speak() { //虚函数
        cout << "叫！" << endl;
    }
};

class Cat : public Animal { //继承
public:
    Cat() : Animal("cat") {}
    void speak() { //子类重写父类的虚函数
        cout << "喵！" << endl;
    }
};

class Dog : public Animal { //继承
public:
    Dog() : Animal("dog") {}
    void speak() { //子类重写父类的虚函数
        cout << "汪！" << endl;
    }
};

void doSpeak(Animal &a) { //父类指针或引用指向子类
    a.speak();
}

void test() {
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);

}

int main() {

    test();

    system("pause");

    return 0;
}