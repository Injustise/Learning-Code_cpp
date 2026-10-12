### 一些笔记
1. **Lambda 底层就是仿函数**：
    - 当你写下这段代码时：
    ``` c++
    int threshold = 50;
    auto my_lambda = [&threshold](const Student& a, const Student& b) -> bool {
        return abs(a.score - threshold) < abs(b.score - threshold);
    };
    ```
    - 编译器会自动生成一个未命名类（等价于手写仿函数，无性能差异）：
    ``` c++
    struct __AnonymousLambda_123 {
    private:
        int& __threshold_ref; // 成员变量，用来存储捕获的 &threshold 

    public:
        __AnonymousLambda_123(int& threshold) 
        : __threshold_ref(threshold) {}

        // 重载函数调用运算符
        bool operator()(const Student& a, const Student& b) const {
        // 函数体内部使用成员变量 __threshold_ref
            return abs(a.score - __threshold_ref) < abs(b.score - __threshold_ref);
        }
    };
    ```
2. Lambda 的写法：
    ```
    [捕获列表](参数列表) -> 返回类型 { 函数体 }
    ```
    - 捕获子句分类：
 
    |写法|含义|
    |:--|:--| 
    | [] | 空捕获。完全不访问外部任何变量。 |
    | [&] | 按引用捕获。 |
    | [=] | 按值捕获。
    - 捕获子句写法：
      - 当你直接写 `[&]`，编译器只会捕获 Lambda 函数体内实际用到的变量。
      - 当你具体写 `[&threshold`（显式捕获），编译器只能捕获 `&threshold`。
       
      这里建议使用显式捕获，其可读性强，安全性高。 