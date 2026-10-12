#include <iostream>
using namespace std;

int main() {

    int a = 1, b = 2;
    int * p = &a; //指针的定义：数据类型 * 指针变量名 = & 变量名

    printf("p = %d\n", p); //输出指针变量p的值，即a的地址
    printf("*p = %d\n", *p); //输出指针变量p指向的值，即a的值
    
    const int * p1 = &a; //常量指针（指向常量的指针）：指针指向可以改，但指针指向的值不可以改
    p1 = &b;
    // *p1 = 3; 
    printf("*p1 = %d\n", *p1);
    
    int * const p2 = &a; //指针常量（指针是常量）：指针指向不可以改，但指针指向的值可以改
    // p2 = &b;
    *p2 = 3; //此时 a 的值被修改为 3
    printf("*p2 = %d\n", *p2);

    a = 1; 
    const int * const p3 = &a; //常量指针常量：指针指向不可以改，指针指向的值也不可以改
    // p3 = &b;
    // *p3 = 3;
    printf("*p3 = %d\n", *p3); 

    system("pause");

    return 0;
}