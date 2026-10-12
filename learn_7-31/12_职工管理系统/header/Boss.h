#pragma once

#include <iostream>
#include <string>
#include "Staff.h"

using namespace std;

class Boss : public Staff {
public:
    Boss(string id, string name, int pos);
    void showifo();
};