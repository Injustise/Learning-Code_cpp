#include <iostream>
#include <fstream>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

void Show_mainMenu() { //系统主菜单
    std::cout << "=============== 欢迎使用机房预约系统！===============" << std::endl;
    std::cout << "请选择您的登录身份：" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "| 1：学    生 |" << std::endl;
    std::cout << "| 2：老    师 |" << std::endl;
    std::cout << "| 3：管 理 员 |" << std::endl;
    std::cout << "| 0：退出系统 |" << std::endl;
    std::cout << "---------------" << std::endl;
}

void Administrator_Menu(User *user) { //管理员子菜单

    user->openMenu();
    Administrator *admin = static_cast<Administrator*>(user);

    int select;
    while(std::cin >> select) {
        switch(select) {
            case 1: { //添加账号
                admin->Add_User();
                break;
            }
            case 2: { //查看账号
                admin->Show_User();
                break;
            }
            case 3: { //查看机房
                admin->Show_Computer();
                break;
            }
            case 4: { //清空预约
                admin->Clear();
                break;
            }
            case 0: { //退出登录
                std::cout << "成功退出登录！" << std::endl;
                system("pause");
                system("cls");
                return;
            }
            default: {
                std::cout << "输入错误，请重新输入！" << std::endl;
                system("pause");
                system("cls");
            }
        }
        admin->openMenu();
    }
}

void Student_Menu(User *user) { //学生子菜单
    user->openMenu();
    Student *stu = static_cast<Student*>(user);

    int select;
    while(std::cin >> select) {
        switch(select) {
            case 1: { //申请预约
                stu->Apply_Appointment();
                break;
            }
            case 2: { //我的预约
                stu->Show_myAppointment();
                break;
            }
            case 3: { //所有预约
                stu->Show_allAppointment();
                break;
            }
            case 4: { //取消预约
                stu->Cancel_Appointment();
                break;
            }
            case 0: { //退出登录
                std::cout << "成功退出登录！" << std::endl;
                system("pause");
                system("cls");
                return;
            }
            default: {
                std::cout << "输入错误，请重新输入！" << std::endl;
                system("pause");
                system("cls");
            }
        }
        stu->openMenu();
    }
}

void Teacher_Menu(User *user) { //老师子菜单
    user->openMenu();
    Teacher *tea = static_cast<Teacher*>(user);

    int select;
    while(std::cin >> select) {
        switch(select) {
            case 1: { //所有预约
                tea->Show_allAppointment();
                break;
            }
            case 2: { //审核预约
                tea->Review_Appointment();
                break;
            }
            case 0: { //退出登录
                std::cout << "成功退出登录！" << std::endl;
                system("pause");
                system("cls");
                return;
            }
            default: {
                std::cout << "输入错误，请重新输入！" << std::endl;
                system("pause");
                system("cls");
            }
        }
        tea->openMenu();
    }
}


bool Check_Login12(std::string file_name, std::string id, std::string name, std::string password) { //登录验证
    std::ifstream ifs(file_name, std::ios::in);

    std::string fid, fname, fpassword;
    while(ifs >> fid && ifs >> fname && ifs >> fpassword) {
        if(fid == id && fname == name && fpassword == password) 
            return true;
    }
    return false;
}
bool Check_Login3(std::string file_name, std::string name, std::string password) { //登录验证
    std::ifstream ifs(file_name, std::ios::in);

    std::string fname, fpassword;
    while(ifs >> fname && ifs >> fpassword) {
        if(fname == name && fpassword == password) 
            return true;
    }
    return false;
}

void Login(std::string file_name, int type) { //登录
    User *user = nullptr; //基类接口

    std::string id, name, password;
    if(type == 1 || type == 2) {
        std::cout << (type == 1 ? "请输入您的学号：" : "请输入您的职工号：") << std::endl;
        std::cin >> id; 
    }
    std::cout << "请输入您的姓名：" << std::endl;
    std::cin >> name;
    std::cout << "请输入您的密码：" << std::endl;
    std::cin >> password;

    switch(type) { //派生类接入接口
        case 1: {
            if(Check_Login12(file_name, id, name, password)) {
                std::cout << "学生登录成功！" << std::endl;
                system("pause");
                system("cls");
                // 进入学生子菜单
                user = new Student(id, name, password); //学生
                Student_Menu(user); 
                return;
            }
            break;
        }
        case 2: {
            if(Check_Login12(file_name, id, name, password)) {
                std::cout << "老师登录成功！" << std::endl;
                system("pause");
                system("cls");
                // 进入老师子菜单
                user = new Teacher(id, name, password); //老师
                Teacher_Menu(user);
                return;
            }
            break;
        }
        case 3: {
            if(Check_Login3(file_name, name, password)) {
                std::cout << "管理员登录成功！" << std::endl;
                system("pause");
                system("cls");
                // 进入管理员子菜单
                user = new Administrator(name, password); //管理员
                Administrator_Menu(user);
                return;
            }
            break;
        }
    }
    std::cout << "登录失败！" << std::endl;
    system("pause");
    system("cls");
}

void Exit_System() { //退出系统
    std::cout << "成功退出机房预约系统，欢迎您的下次使用！" << std::endl;
    system("pause");
    system("cls");
    exit(0);
}

int main() {
    Show_mainMenu();
    int select;
    while(std::cin >> select) {
        switch(select) {
            case 1: { //学生
                Login("D://code//learn_7-31//18_机房预约系统//build//student.txt", 1);
                break;
            }

            case 2: { //老师
                Login("D://code//learn_7-31//18_机房预约系统//build//teacher.txt", 2);
                break;
            }

            case 3: { //管理员
                Login("D://code//learn_7-31//18_机房预约系统//build//administrator.txt", 3);
                break;
            }

            case 0: { //退出
                Exit_System();
                break;
            }

            default: {
                std::cout << "输入错误，请重新输入！" << std::endl;
                system("pause");
                system("cls");
            }
        }
        Show_mainMenu();
    }

    return 0;
}