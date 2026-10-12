### 一些笔记
1. - `std::move` 是一种**类型转换：把左值强制转换为右值**。
        ``` c++
        class Person {
        std::string name;
        public:
            Person(std::string n) : name(std::move(n)) {}
        };
        ``` 
    - 传递左值时，
        ``` c++
        std::string s = "Alice";
        Person p(s);
        ```
        - 总开销：一次拷贝（s→n）+ 一次移动（n→name）。
        - 如果不用 `std::move`，而直接用 `name(n)`，那就是两次拷贝（s→n，n→name）
    - 传递右值时，
        ``` c++
        Person p(std::string("Alice")); //临时对象
        Person p("Alice"); //字符串字面量，临时构造
        ```
        - 总开销：两次移动（"Alice"→n，n→name）。
        - 如果不用 `std::move`，而直接用 `name(n)`，那就是一次移动（"Alice"→n）+ 一次拷贝（n→name）。
    - *==注意==：这里的 **`name(n)` 本质上是调用 `std::string` 类的拷贝构造函数**（因为 `n` 为左值），来初始化成员 `name`，同时标准库强制要求 std::string 的拷贝必须是深拷贝（因为对于 `std::string` 内部的堆内存指针，必须是深拷贝，防止浅拷贝重复释放带来报错）。*
    - 所以这里 `std::move(n)` 把 `n` 由左值强制转化为右值，就是在**优化第二步的拷贝操作 `name(n)` 为转移操作**。
    - 转移操作：
        ``` c++
        name(std::move(n));   // 调用 std::string 的移动构造函数
        ```
        ``` 
        name 内部指针 → "Alice" ([prt]: 0x0011)
        n 内部指针 → (null or empty)
        //对比浅拷贝：name 内部指针 → "Alice" ([prt]: 0x0011) 
        //           n 内部指针 → "Alice" ([prt]: 0x0011)
        //对比深拷贝：name 内部指针 → "Alice" ([prt]: 0x0015)
        //           n 内部指针 → "Alice" ([prt]: 0x0011)           
        ``` 
    - 对于基础数据类型（如 `int`）:
        ``` c++
        class Person {
        int age;
        public:
            Person(age a) : age(a) {} //加与不加 std::move 没有任何性能或语义上的区别
        };
        ``` 
        **对于 `std::string` 内部的堆内存指针，移动可以只转移指针，省去内存分配和复制数据的开销**。
        而 `int` 是基础类型（标量类型），没有资源管理（不持有堆内存、文件句柄等），内部就是 4 个字节的整数（区别于 `std::string` 类）。故 `age(a)` 和 `age(std::move(a))` 完全是同一码事，**都是 4 字节拷贝，无任何开销差异**。
2.  - 移动的本质是**转移资源所有权**，这便要求修改对象（例如：将 `cls` 的内部指针置空），但 `cls` 带有 `const` 修饰，编译器又不允许修改它。
        ``` c++
        Animal(const string& cls) : m_class(cls) {} 
                              //m_class(std::move(cls)) //无意义，没有任何性能提升  
        ```
    - | 写法 | 传入左值  | 传入右值 |
      |:--|:--|:--|
      |`const string&` + 拷贝|1 次拷贝|1 次拷贝|
      |`string` + `move`（推荐）|1 次拷贝 + 1 次移动|2 次移动| 


  