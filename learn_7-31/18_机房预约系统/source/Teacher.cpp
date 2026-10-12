#include "Teacher.h"

Teacher::Teacher(std::string id, std::string name, std::string password) {
    m_id = std::move(id);
    m_name = std::move(name);
    m_password = std::move(password);
}

void Teacher::openMenu() { //打开菜单
    std::cout << "欢迎老师：" << this->m_name << " 登录！" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "| 1：所有预约 |" << std::endl;
    std::cout << "| 2：审核预约 |" << std::endl;
    std::cout << "| 0：退出登录 |" << std::endl;
    std::cout << "---------------" << std::endl;
}

void Teacher::Show_allAppointment() { //查看所有预约（通过容器读取文件信息）
    Appointment Appfile; //容器读入文件

    if(Appfile.m_size == 0) {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "所有预约记录：" << std::endl;
    std::cout << "------------" << std::endl;
    for(int i = 0; i < Appfile.m_size; i++) { //通过遍历容器读取文件信息
        std::cout << "预约日期：" << Appfile.app[i]["data:"] 
                  << "\t时段：" << (Appfile.app[i]["interval:"] == "1" ? "上午" : "下午") 
                  << "\t学号：" << Appfile.app[i]["stuID:"]
                  << "\t姓名：" << Appfile.app[i]["stuName:"]
                  << "\t机房：" << Appfile.app[i]["room:"] 
                  << "\t\t状态：";
        if(Appfile.app[i]["status:"] == "1") std::cout << "审核中..." << std::endl;
        else if(Appfile.app[i]["status:"] == "2") std::cout << "已预约" << std::endl;
        else if(Appfile.app[i]["status:"] == "3") std::cout << "预约失败" << std::endl;
        else std::cout << "已取消预约" << std::endl;
    }
    std::cout << "------------" << std::endl;

    system("pause");
    system("cls");
}

void Teacher::Review_Appointment() { //审核预约（通过容器修改文件信息）
    Appointment Appfile; //容器读入文件

    if(Appfile.m_size == 0) {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::vector<int> vec;
    for(int i = 0; i < Appfile.m_size; i++) {
        if(Appfile.app[i]["status:"] == "1") {
            vec.push_back(i);
        }
    }

    if(vec.size() == 0) {
        std::cout << "预约已全部审核完毕" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "待审核的预约如下：" << std::endl; //列表
    std::cout << "------------" << std::endl;
    for(int i = 0; i < vec.size(); i++) {
        std::cout << "序号 " << i + 1 << "：" 
                  << "\t预约日期：" << Appfile.app[vec[i]]["data:"] 
                  << "\t时段：" << (Appfile.app[vec[i]]["interval:"] == "1" ? "上午" : "下午") 
                  << "\t学号：" << Appfile.app[vec[i]]["stuID:"]
                  << "\t姓名：" << Appfile.app[vec[i]]["stuName:"]
                  << "\t机房：" << Appfile.app[vec[i]]["room:"] 
                  << "\t\t状态：" << "审核中..." << std::endl;
    }
    std::cout << "------------" << std::endl;


    std::cout << "请选择审核的序号：" << std::endl; //选择
    std::cout << "（0：退出审核）" << std::endl;
    int pos = 0;
    while(std::cin >> pos) {
        if(pos == 0) {
            std::cout << "已取消操作！" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        if(pos >= 1 && pos <= vec.size()) break;
        std::cout << "输入错误，请重新输入！" << std::endl;
    }

    std::cout << "请输入审核结果：" << std::endl;
    std::cout << "1：通过  2：拒绝" << std::endl;
    int select = 0;
    while(std::cin >> select) {
        if(select == 1 || select == 2) break;
        std::cout << "输入错误，请重新输入！" << std::endl;
    }

    pos = vec[pos - 1];

    std::cout << pos << std::endl;

    Appfile.app[pos]["status:"] = (select == 1 ? "2" : "3"); //通过容器修改文件信息

    std::cout << "预约日期：" << Appfile.app[pos]["data:"] 
              << "\t时段：" << (Appfile.app[pos]["interval:"] == "1" ? "上午" : "下午") 
              << "\t学号：" << Appfile.app[pos]["stuID:"]
              << "\t姓名：" << Appfile.app[pos]["stuName:"]
              << "\t机房：" << Appfile.app[pos]["room:"] 
              << "\t\t状态：" << (select == 1 ? "已预约" : "预约失败") << std::endl;

    std::cout << "审核完毕！" << std::endl;
    Appfile.Update(); //即时更新：修改对象 -> 对象写入文件 -> 修改文件

    system("pause");
    system("cls");
}