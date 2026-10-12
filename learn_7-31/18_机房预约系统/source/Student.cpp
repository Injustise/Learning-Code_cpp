#include "Student.h"

Student::Student(std::string id, std::string name, std::string password) {
    m_id = std::move(id);
    m_name = std::move(name);
    m_password = std::move(password);
}

void Student::openMenu() { //打开菜单
      std::cout << "欢迎学生：" << this->m_name << " 登录！" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "| 1：申请预约 |" << std::endl;
    std::cout << "| 2：我的预约 |" << std::endl;
    std::cout << "| 3：所有预约 |" << std::endl;
    std::cout << "| 4：取消预约 |" << std::endl;
    std::cout << "| 0：退出登录 |" << std::endl;
    std::cout << "---------------" << std::endl;
}

void Student::Apply_Appointment() { //申请预约（直接写入文件）
    std::cout << "机房开放时间为周一至周五！" << std::endl;
    std::cout << "请选择申请预约的时间：" << std::endl;
    std::cout << "1：周一" << std::endl;
    std::cout << "2：周二" << std::endl;
    std::cout << "3：周三" << std::endl;
    std::cout << "4：周四" << std::endl;
    std::cout << "5：周五" << std::endl;
    std::cout << "0：放弃预约" << std::endl;

    int data = 0;
    while(std::cin >> data) {
        if(data >= 1 && data <= 5) break;
        if(data == 0) {
            std::cout << "即将返回主菜单" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        std::cout << "输入有误，请重新输入！" << std::endl;
    }

    int interval = 0;
    std::cout << "请选择申请预约的时间段：" << std::endl;
    std::cout << "1：上午" << std::endl;
    std::cout << "2：下午" << std::endl;
    while(std::cin >> interval) {
        if(interval == 1 || interval == 2) break;
        std::cout << "输入有误，请重新输入！" << std::endl;
    }

    int room = 0;
    std::cout << "请选择申请预约的机房：" << std::endl;
    std::cout << "1：01 号机房" << std::endl;
    std::cout << "2：02 号机房" << std::endl;
    std::cout << "3：03 号机房" << std::endl;
    while(std::cin >> room) {
        if(room >= 1 && room <= 3) break;
        std::cout << "输入有误，请重新输入！" << std::endl;
    }
    
    std::cout << "预约成功！" << std::endl;
    std::cout << "审核中..." << std::endl;

    std::ofstream ofs("D://code//learn_7-31//18_机房预约系统//build//appointment.txt", std::ios::out | std::ios::app);

    ofs << "data:" << data << ' '
        << "interval:" << interval << ' '
        << "stuID:" << this->m_id << ' '
        << "stuName:" << this->m_name << ' '
        << "room:" << room << ' '
        << "status:" << 1 << std::endl;

    ofs.close();

    system("pause");
    system("cls");
}
    
void Student::Show_myAppointment() { //查看我的预约（通过容器读取文件信息）
    Appointment Appfile; //容器读入文件

    if(Appfile.m_size == 0) {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "我的预约记录：" << std::endl;
    std::cout << "------------" << std::endl;
    bool flag = false;
    for(int i = 0; i < Appfile.m_size; i++) { //通过遍历容器读取文件信息
        if(Appfile.app[i]["stuID:"] == this->m_id) {
            flag = true;
            std::cout << "预约日期：" << Appfile.app[i]["data:"] 
                      << "\t时段：" << (Appfile.app[i]["interval:"] == "1" ? "上午" : "下午") 
                      << "\t机房：" << Appfile.app[i]["room:"] 
                      << "\t\t状态：";
            if(Appfile.app[i]["status:"] == "1") std::cout << "审核中..." << std::endl;
            else if(Appfile.app[i]["status:"] == "2") std::cout << "已预约" << std::endl;
            else if(Appfile.app[i]["status:"] == "3") std::cout << "预约失败" << std::endl;
            else std::cout << "已取消预约" << std::endl;
        }
    }
    if(!flag) std::cout << "（无预约记录）" << std::endl;
    std::cout << "------------" << std::endl;

    system("pause");
    system("cls");
}

void Student::Show_allAppointment() { //查看所有预约（通过容器读取文件信息）
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

void Student::Cancel_Appointment() { //取消预约（通过容器修改文件信息）
    Appointment Appfile;

    if(Appfile.m_size == 0) {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::vector<int> vec;
    for(int i = 0; i < Appfile.m_size; i++) {
        if(Appfile.app[i]["stuID:"] == this->m_id && (Appfile.app[i]["status:"] == "1" || Appfile.app[i]["status:"] == "2")) {
            vec.push_back(i);
        }
    }

    if(vec.size() == 0) {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "可取消的预约如下：" << std::endl; //列表
    std::cout << "------------" << std::endl;
    for(int i = 0; i < vec.size(); i++) {
        std::cout << "序号 " << i + 1 << "：" 
                  << "\t预约日期：" << Appfile.app[vec[i]]["data:"] 
                  << "\t时段：" << (Appfile.app[vec[i]]["interval:"] == "1" ? "上午" : "下午") 
                  << "\t机房：" << Appfile.app[vec[i]]["room:"] 
                  << "\t\t状态：";
        if(Appfile.app[vec[i]]["status:"] == "1") std::cout << "审核中..." << std::endl;
        else if(Appfile.app[vec[i]]["status:"] == "2") std::cout << "已预约" << std::endl;
        else if(Appfile.app[vec[i]]["status:"] == "3") std::cout << "预约失败" << std::endl;
        else std::cout << "已取消预约" << std::endl;
    }
    std::cout << "------------" << std::endl;


    std::cout << "请选择取消的预约序号：" << std::endl; //选择
    std::cout << "（0：放弃取消预约）" << std::endl;
    int select;
    while(std::cin >> select) {
        if(select == 0) {
            std::cout << "已取消操作！" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        if(select >= 1 && select <= vec.size()) break;
        std::cout << "输入错误，请重新输入！" << std::endl;
    }
    int pos = vec[select - 1];
    Appfile.app[pos]["status:"] = "4"; //通过容器修改文件信息
    std::cout << "预约日期：" << Appfile.app[pos]["data:"] 
                      << "\t时段：" << (Appfile.app[pos]["interval:"] == "1" ? "上午" : "下午") 
                      << "\t机房：" << Appfile.app[pos]["room:"] 
                      << "\t\t状态：" << "已取消预约" << std::endl;

    std::cout << "取消成功！" << std::endl;
    Appfile.Update(); //即时更新：修改对象 -> 对象写入文件 -> 修改文件

    system("pause");
    system("cls");
}