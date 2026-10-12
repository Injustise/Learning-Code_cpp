#include <iostream>

#include "point.h" //点
#include "circle.h" //圆

using namespace std;

void check(const Point &a, const Circle &b) { //引用传递（指针传递）大对象，节约空间。const 只读不写
    int ax = a.get_x(), ay = a.get_y(); //取点的坐标
    int bx = b.get_o().get_x(), by = b.get_o().get_y(); //取圆点的坐标
    int dis = (ax - bx) * (ax - bx) + (ay - by) * (ay - by); //两点间距离公式
    int r = b.get_r();
    if(dis < r * r) cout << "点在圆内" << endl; 
    else if(dis > r * r) cout << "点在圆外" << endl;
    else cout << "点在圆上" << endl;
}

int main() {

    Circle c;
    c.set_r(10); //设圆的半径
    Point o;
    o.set_x(10); //设圆点的坐标
    o.set_y(0);
    c.set_o(o); 

    Point p;
    p.set_x(10); //设点的坐标
    p.set_y(10);

    check(p, c); //判断点和圆的位置关系

    system("pause");

    return 0;
}