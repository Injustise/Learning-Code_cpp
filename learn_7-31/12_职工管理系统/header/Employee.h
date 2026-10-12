#pragma once

#include <iostream>
#include <string>
#include "Staff.h"

using namespace std;

class Employee : public Staff {
public:
    Employee(string id, string name, int pos);
    void showifo();
};