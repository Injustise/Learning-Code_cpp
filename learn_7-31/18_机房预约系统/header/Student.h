#pragma once

#include <vector>
#include "User.h"

class Student : public User {
public:
    std::string m_id;
public:
    Student() {};
    Student(std::string id, std::string name, std::string password);

    void openMenu(); //打开菜单

    void Apply_Appointment(); //申请预约

    void Show_myAppointment(); //查看我的预约

    void Show_allAppointment(); //查看所有预约

    void Cancel_Appointment(); //取消预约
};