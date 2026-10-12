#include "Idtime.h"

string generateTimeID() {
    auto now = chrono::system_clock::now(); //获取时间戳

    time_t t = chrono::system_clock::to_time_t(now); //将时间点 now 转换为传统的 time_t 类型
    tm *tm = localtime(&t); //将 time_t 转换为 tm 类型表示本地日历时间

    ostringstream oss;
    oss << put_time(tm, "%y%m%d");

    //获取从纪元到当前时间点（now）的时钟周期数（通常为纳秒或微秒），作为种子
    static unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    //梅森旋转随机数生成器（Mersenne Twister），使用 seed 初始化
    static mt19937 gen(seed);
    //定义一个均匀分布的整数区间 [0, 999]
    static uniform_int_distribution<int> dist(0,999);
    //调用分布对象 dist 并传入引擎 gen，生成一个 0~999 的随机整数
    int randomPart = dist(gen);

    //三者静态，确保随机序列在多次调用中持续（而不是每次重新生成相同的序列）

    //setw(3) 设置宽度为 3 个字符，setfill('0') 设置填充字符为 '0'
    oss << setw(3) << setfill('0') << randomPart;
    

    return oss.str();
}