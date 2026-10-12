#include<iostream>
using namespace std;

int main() {

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d * %d = %d\t", j, i, j * i); //\t 表示制表符，对应 8 个空格。
        }
        printf("\n");
    }

    printf("1234567\t12345678\n"); // 8 格余 1 格
    printf("12345678\t1234578\n"); // 不存在余 0 格，自动再补 8 格

    system("pause");

    return 0;
}