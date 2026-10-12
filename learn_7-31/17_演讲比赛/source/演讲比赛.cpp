#include <iostream>
#include  "SpeechContest.h"

int main() {

    SpeechContest mySpeechContest;

    mySpeechContest.ShowMenu();

    int select;
    while(std::cin >> select) {

        switch(select) {
            case 1: { //开始比赛
                mySpeechContest.Start();
                break;
            }
            
            case 2: { //查看记录
                mySpeechContest.ShowRecord();
                break;
            }

            case 3: { //清空记录
                mySpeechContest.ClearRecord();
                break;
            }
            
            case 0: { //退出程序
                mySpeechContest.Exit();
                break;
            }

            default: {
                std::cout << "输入错误，请重新输入！" << std::endl;
                system("pause");
                system("cls");
            }
        }
        mySpeechContest.ShowMenu();
    }

    return 0;
}