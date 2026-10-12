#include <iostream>
#include <string>

template<class Type>
class Array {
private:
    Type *m_Array;
    int m_Capacity;
    int m_Size;
public:
    Array(int Capacity) {
        this->m_Array = new Type[Capacity]; //new Type[Capacity] 会为每个元素调用默认构造函数（对于类类型）。如果 Type 没有默认构造函数，编译器就会报错。
        m_Capacity = Capacity;
        m_Size = 0;
    }
    ~Array() {
        if(this->m_Array != nullptr) {
            delete[] this->m_Array;
            this->m_Array = nullptr;
        }
    }
    Array(const Array &a) {
        this->m_Capacity = a.m_Capacity;
        this->m_Size = a.m_Size;
        this->m_Array = new Type[a.m_Capacity];
        for(int i = 0; i < this->m_Size; i++) {
            this->m_Array[i] = a.m_Array[i];
        }
    }
    Array& operator =(const Array &a) {
        if(m_Array != nullptr) {
            delete[] this->m_Array;
            this->m_Array = nullptr;
        }
        this->m_Capacity = a.m_Capacity;
        this->m_Size = a.m_Size;
        this->m_Array = new Type[a.m_Capacity];
        for(int i = 0; i < this->m_Size; i++) {
            this->m_Array[i] = a.m_Array[i];
        }
        return *this;
    }
    Type& operator [](int x) const {
        return this->m_Array[x];
    }
    void Push_Back(Type x) {
        if(m_Size == m_Capacity) return;
        this->m_Array[this->m_Size++] = x;
    }
    void Pop_Back() {
        if(!m_Size) return;
        this->m_Size--;
    }
    int getCapacity() const {
        return this->m_Capacity;
    }
    int getSize() const { 
        return this->m_Size;
    }
};

class Person {
private:
    std::string m_name;
    int m_age;
public:
    Person() {} //默认构造函数（无参 + 空实现）
    Person(std::string name, int age) : m_name(std::move(name)), m_age(age) {}
    void showifo() const {
        std::cout << "name: " << m_name 
                  << "\tage: " << m_age << std::endl;
    }
};

void test01() {
    Array<int> a(10);
    for(int i = 0; i < 10; i++) a.Push_Back(i);
    a.Pop_Back();
    std::cout << "Capacity: " << a.getCapacity() << std::endl
              << "Size: " << a.getSize() << std::endl;
    Array<int> b = a;
    for(int i = 0; i < b.getSize(); i++)
        std::cout << b[i] << ' ';
    std::cout << std::endl;

}

void PrintPersonArray(const Array<Person> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        arr[i].showifo();
    }
}

void test02() {
    Array<Person> a(10);

    Person p1("John", 20);
    Person p2("Alice", 18);
    Person p3("Sam", 21);

    a.Push_Back(p1);
    a.Push_Back(p2);
    a.Push_Back(p3);

    PrintPersonArray(a);
}

int main() {

    test01();
    test02();
    
    system("pause");

    return 0;
}