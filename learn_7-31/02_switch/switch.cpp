#include<iostream>
using namespace std;
int main() {

    int score;
    printf("Enter your score for the film (0-100): ");

    scanf("%d", &score);

    switch(score) { //程序会计算 switch 括号里的表达式，得到一个值。然后跳转（goto）到与该值匹配的 case 标签处，并从这里开始执行。
        case 100: //从匹配的 case 开始，程序会无视后面的所有 case 标签，一直顺序向下执行，直到遇到 break 语句，或者遇到整个 switch 结构的右花括号 } 为止。
            printf("You rated the film as Perfect!\n");
            break;
        case 90 ... 99: //在标准 C++ 中，case 标签不能使用范围表达式，这种语法是 GCC 的扩展。
            printf("You rated the film as Excellent\n");
            break; 
        case 80 ... 89:
            printf("You rated the film as Good\n");
            break;
        case 70 ... 79:
            printf("You rated the film as Average\n");
            break;
        case 60 ... 69:
            printf("You rated the film as Poor\n");
            break;
        default:
            printf("You rated the film as Terrible\n");
    }

    system("pause");

    return 0;
}