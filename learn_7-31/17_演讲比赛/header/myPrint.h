#pragma once

#include <iostream>
#include "Speaker.h"

class myPrint {
private:
    int m_index;
public:
    myPrint(int index);
    void operator()(const Speaker& a) const;
};