#include "circle.h" //Ô²µÄ¶¨Òå


        void Circle::set_o(Point o) {
            mo = o;
        }
        void Circle::set_r(int r) {
            mr = r;
        }
        Point Circle::get_o() const {
            return mo;
        }
        int Circle::get_r() const {
            return mr;
        }
