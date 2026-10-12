#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void test01() {
    ofstream ofs;
    ofs.open("test01.txt", ios::out);
    ofs << "姓名：张竞航" << endl
        << "性别：男" << endl
        << "年龄：18" << endl;
    ofs.close();
}

void test02() {
    ifstream ifs;
    ifs.open("test01.txt", ios::in);
    if(!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }
    //第一种读入方式：
    /*char buf[1024] = {0};
    while(ifs >> buf) {
        cout << buf << endl;
    }*/
    //第二种读入方式：
    /*char buf[1024] = {0};
    while(ifs.getline(buf,sizeof(buf))) {
        cout << buf << endl;
    }*/
   //第三种读入方式：
    string buf;
    while(getline(ifs,buf)) {
        cout << buf << endl;
    }
}

int main() {
    //test01();
    test02();

    system("pause");

    return 0;
}