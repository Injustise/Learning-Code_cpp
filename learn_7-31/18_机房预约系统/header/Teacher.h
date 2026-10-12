#pragma once

#include <vector>
#include "User.h"

class Teacher : public User {
public:
    std::string m_id;
public:
    Teacher() {};
    Teacher(std::string id, std::string name, std::string password);

    void openMenu(); //打开菜单

    void Show_allAppointment(); //查看所有预约

    void Review_Appointment(); //审核预约
};