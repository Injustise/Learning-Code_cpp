#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Appointment.h"

class User {
public:
    std::string m_name;
    std::string m_password;
public:
    virtual void openMenu() = 0;
};