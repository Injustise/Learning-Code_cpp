#include <iostream>

template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void mySort(T a[], int n) {
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= n - i; j++) {
            if(a[j] > a[j + 1]) mySwap(a[j], a[j + 1]);
        }
}

void test01() {
    int a[100];
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    mySort(a, n);
    for(int i = 1; i <= n; i++) std::cout << a[i] << ' ';
    std::cout << std::endl;
}

void test02() {
    double b[100];
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> b[i];
    mySort(b, n);
    for(int i = 1; i <= n; i++) std::cout << b[i] << ' ';
    std::cout << std::endl;
}

void test03() {
    char c[100];
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> c[i];
    mySort(c, n);
    for(int i = 1; i <= n; i++) std::cout << c[i] << ' ';
    std::cout << std::endl;
}

int main() {
    std::cout << "int:" << std::endl;
    test01();

    std::cout << "double:" << std::endl;
    test02();

    std::cout << "char" << std::endl;
    test03();

    system("pause");

    return 0;
}