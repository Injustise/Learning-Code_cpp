#pragma once

#include <map>
#include <algorithm>
#include "User.h"

class Administrator : public User {
public:                            
    std::map<std::string, std::pair<std::string, std::string>> vstu; //学生账号（key：学号）
    std::map<std::string, std::pair<std::string, std::string>> vtea; //老师账号（key：职工号）
public:
    Administrator() {};
    Administrator(std::string name, std::string password);

    void openMenu(); //打开菜单

    void Add_User(); //添加账号

    void Show_User(); //查看所有账号

    void Show_Computer(); //查看所有机房

    void Clear(); //清空所有预约

    void Init(); //初始化容器
};