#include "Appointment.h"

std::string Appointment::Remove(std::string str) { //提取有效字符串
    int pos = str.find(":"); //find 切割
    if(pos != -1) {
        return str.substr(pos + 1, str.size() - pos); //substr 提取
    }
    return "";
}

Appointment::Appointment() { //初始化：文件 -> 容器（方便读改）
    std::ifstream ifs("D://code//learn_7-31//18_机房预约系统//build//appointment.txt", std::ios::in);
  
    this->m_size = 0; //一维序号
    std::map<std::string, std::string> temp; //二位信息名称
    std::string data, interval, id, name, room, status;
    while(ifs >> data && ifs >> interval && ifs >> id && ifs >> name && ifs >> room && ifs >> status) { 
        temp.insert(make_pair("data:", Remove(data)));
        temp.insert(make_pair("interval:", Remove(interval)));
        temp.insert(make_pair("stuID:", Remove(id)));
        temp.insert(make_pair("stuName:", Remove(name)));
        temp.insert(make_pair("room:", Remove(room)));
        temp.insert(make_pair("status:", Remove(status)));
        this->app[this->m_size++] = temp; //读入容器 app
        temp.clear();
    }
}

void Appointment::Update() { //即时更新：修改对象 -> 对象写入文件 -> 修改文件 
    std::ofstream ofs("D://code//learn_7-31//18_机房预约系统//build//appointment.txt", std::ios::trunc);

    for(int i = 0; i < this->m_size; i++) {
        ofs << "data:" << app[i]["data:"] << ' '
        << "interval:" << app[i]["interval:"] << ' '
        << "stuID:" << app[i]["stuID:"] << ' '
        << "stuName:" << app[i]["stuName:"] << ' '
        << "room:" << app[i]["room:"] << ' '
        << "status:" << app[i]["status:"] << std::endl; //写入文件 file
    }
    ofs.close();
}