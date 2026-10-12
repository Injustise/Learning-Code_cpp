#include "myPrint.h"

myPrint::myPrint(int index) {
    m_index = index;
}

void myPrint::operator()(const Speaker& a) const {
    a.showifo(m_index);
}