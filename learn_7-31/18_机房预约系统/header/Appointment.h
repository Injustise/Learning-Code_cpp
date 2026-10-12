#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class Appointment { //通过修改容器（与文件相映射），实现修改文件
public:
    std::map<int, std::map<std::string, std::string>> app; //双层嵌套 map ~ 二维关键字（一维序号，二维信息名称）
    int m_size; 
public:
    Appointment();
    std::string Remove(std::string str); //提取有效字符串
    void Update(); //即时更新文件（容器与文件相映射）
};