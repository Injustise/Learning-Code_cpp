#pragma once

#include <iostream>
#include <string>

using namespace std;

class Staff {
public: 
    string m_id;
    string m_name;
    int m_position;
public:
    virtual void showifo() = 0;
};