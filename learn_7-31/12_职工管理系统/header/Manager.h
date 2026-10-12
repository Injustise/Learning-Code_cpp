#pragma once

#include <iostream>
#include <string>
#include "Staff.h"

using namespace std;

class Manager : public Staff {
public:
    Manager(string id, string name, int pos);
    void showifo();
};