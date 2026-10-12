#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circle { //Ô²µÄÉùÃ÷
    private: 
        Point mo;
        int mr;
    public: 
        void set_o(Point o);

        void set_r(int r);

        Point get_o() const;

        int get_r() const; 
};