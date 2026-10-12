#include "Administrator.h"

Administrator::Administrator(std::string name, std::string password) {
    this->m_name = std::move(name);
    this->m_password = std::move(password);

    Init(); //初始化：文件 -> 容器（方便读改）
}

void Administrator::openMenu() { //打开菜单
    std::cout << "欢迎管理员：" << this->m_name << " 登录！" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "| 1：添加账号 |" << std::endl;
    std::cout << "| 2：查看账号 |" << std::endl;
    std::cout << "| 3：查看机房 |" << std::endl;
    std::cout << "| 4：清空预约 |" << std::endl;
    std::cout << "| 0：退出登录 |" << std::endl;
    std::cout << "---------------" << std::endl;
  
}

void Administrator::Add_User() { //添加账号（直接写入文件）
    std::cout << "请选择添加账号的类型：" << std::endl;
    std::cout << "1：学  生" << std::endl;
    std::cout << "2：老  师" << std::endl;

    int select;
    while(std::cin >> select) {
        if(select == 1 || select == 2) break;
        std::cout << "输入错误，请重新输入！" << std::endl;
    }

    std::string id, name, password;

    if(select == 1) { //map：key 判重
        std::cout << "请输入您的学号：" << std::endl;
        std::cin >> id;
        if(vstu.find(id) != vstu.end()) {
            std::cout << "该学号已被注册！" << std::endl;
            system("pause");
            system("cls");
            return; 
        }
    } else {
        std::cout << "请输入您的职工号：" << std::endl;
        std::cin >> id;
        if(vtea.find(id) != vtea.end()) {
            std::cout << "该职工号已被注册！" << std::endl;
            system("pause");
            system("cls");
            return; 
        }
    }
    
    std::cout << "请输入您的姓名：" << std::endl;
    std::cin >> name;
    std::cout << "请输入您的密码：" << std::endl;
    std::cin >> password;


    std::ofstream ofs; //直接写入文件

    if(select == 1) {
        ofs.open("D://code//learn_7-31//18_机房预约系统//build//student.txt", std::ios::out | std::ios::app);
    } else {
        ofs.open("D://code//learn_7-31//18_机房预约系统//build//teacher.txt", std::ios::out | std::ios::app);
    }
    
    ofs << id << ' ' 
        << name << ' '
        << password << std::endl;
    ofs.close();

    std::cout << "添加成功！" << std::endl;
    system("pause");
    system("cls");
}

void Administrator::Show_User() { //查看所有账号（通过容器读取文件信息）
    Init(); //容器读入文件

    std::cout << "请选择查看账号的类型：" << std::endl;
    std::cout << "1：学  生" << std::endl;
    std::cout << "2：老  师" << std::endl;

    int select;
    while(std::cin >> select) {
        if(select == 1 || select == 2) break;
        std::cout << "输入错误，请重新输入！" << std::endl;
    }

    if(select == 1) { //通过遍历容器读取文件信息
        std::cout << "全体学生账号如下：" << std::endl;
        std::cout << "------------" << std::endl;
        std::for_each(vstu.begin(), vstu.end(), 
            [] (const auto& a) {
                std::cout << "学号：" << a.first
                     << "\t姓名：" << a.second.first
                     << "\t密码：" << a.second.second << std::endl;
            });
        std::cout << "------------" << std::endl;
        
    } else {
        std::cout << "全体老师账号如下：" << std::endl;
        std::cout << "------------" << std::endl;
        std::for_each(vtea.begin(), vtea.end(), 
            [] (const auto& a) {
                std::cout << "职工号：" << a.first
                     << "\t姓名：" << a.second.first
                     << "\t密码：" << a.second.second << std::endl;
            });
        std::cout << "------------" << std::endl;
    }

    system("pause");
    system("cls");
}

void Administrator::Show_Computer() { //查看所有机房
    std::cout << "功能尚未完善！" << std::endl;

    system("pause");
    system("cls");
}

void Administrator::Clear() { //清空所有预约
    std::cout << "确定是否清空？" << std::endl;
    std::cout << "1：是  0：否" << std::endl;
    int confirm;
    while(std::cin >> confirm) {
        if(confirm == 1 || confirm == 0) break;
        std::cout << "输入有误，请重新输入！" << std::endl;
    }

    if(confirm) {
        std::ofstream ofs("D://code//learn_7-31//18_机房预约系统//build//appointment.txt", std::ios::trunc);
        ofs.close();
        std::cout << "所有预约已清空！" << std::endl;
    } else {
        std::cout << "已取消操作！" << std::endl;
    }

    system("pause");
    system("cls");
}

void Administrator::Init() { //初始化：文件 -> 容器（方便读改）
    std::ifstream ifs;
    std::string id, name, password;

    this->vstu.clear();
    this->vtea.clear();

    ifs.open("D://code//learn_7-31//18_机房预约系统//build//student.txt", std::ios::in);
    while(ifs >> id && ifs >> name && ifs >> password) {
        vstu[id] = make_pair(name,password); //学生账号
    }
    ifs.close();

    ifs.open("D://code//learn_7-31//18_机房预约系统//build//teacher.txt", std::ios::in);
    while(ifs >> id && ifs >> name && ifs >> password) {
        vtea[id] = make_pair(name,password); //老师账号
    }
    ifs.close();
}