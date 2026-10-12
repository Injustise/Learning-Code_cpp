### 一些笔记
1. `std::time()` 是标准库 `<ctime>` 中定义的函数，用于**获取当前时间戳（秒）**（自 1970 年 1 月 1 日 00:00:00 UTC 以来的秒数）。
    - 函数原型:
      ``` c++
        std::time_t time(std::time_t *timer);
      ```  
    - 函数用法：
      ``` c++
        // 用法 1：通过返回值获取
        std::time_t t = std::time(nullptr); 

        // 用法 2：通过参数获取
        std::time_t t2;
        std::time(&t2);  // 时间戳被写入 t2
      ``` 
2. `std::time_t` 是标准库 `<ctime>` 中定义的**算术类型**，用于**表示时间值**。 
    - C++ 标准（以及 C 标准）故意不指定 time_t 的具体类型，是为了给不同的实现留出灵活性。例如：
        - 在 32 位系统上，time_t 可能被定义为 32 位整数，这会引发 2038 年问题（溢出）。
        - 在 64 位系统上，time_t 通常被定义为 64 位整数，可以表示更久远的时间。
3. `std::localtime()` 是标准库 `<ctime>` 中定义的函数，**将 `std::time_t` 类型的时间戳转换为 `std::tm` 类型的本地时区的分解时间**。
    - 函数原型：
    ``` c++
        std::tm* localtime(const std::time_t *timer);
    ```  
    - 函数用法：
    ``` c++
        std::time_t t = std::time(nullptr); //获取当前时间戳
        std::tm *local = std::localtime(&t); //转为本地时间
    ``` 
4. `std::gmtime()` 是标准库 `<ctime>` 中定义的函数，**将 `syd::time_t` 类型的时间戳转换为 `std::tm` 类型的协调世界时（UTC）的分解时间**。
    - 函数原型：
    ``` c++
        std::tm* gmtime(const std::time_t* timer);
    ``` 
    - 函数用法：
    ``` c++
        std::time_t t = std::time(nullptr); //获取当前时间戳
        std::tm *utc = std::gmtime(&t); //转为协调世界时（UTC）
    ``` 
    >协调世界时（UTC）是一种全球统一时间标准。它不随地区变化，全球同一时刻的 UTC 相同，而各地时区时间通常表示为 UTC 加或减若干小时，例如：北京时间是 UTC+8。
5. `std::mktime()` 是标准库 `<ctime>` 中定义的函数，**将 `std::tm` 类型的本地时区的分解时间转换为 `time_t` 类型的时间戳**。它执行的操作与 `localtime()` 相反。
    - 函数原型：
    ``` c++
        std::time_t mktime(std::tm *timer);
    ``` 
6. `std::tm` 是标准库 `<ctime>` 中定义的**结构体**，用于**表示分解时间（时间点拆分为年、月、日、时、分、秒等独立字段，便于程序读取和格式化输出）**。
   - 结构体定义：
   ``` c++
    struct tm {
        int tm_sec;    // 秒，范围 0-60（60 用于闰秒）
        int tm_min;    // 分，范围 0-59
        int tm_hour;   // 时，范围 0-23
        int tm_mday;   // 日，范围 1-31
        int tm_mon;    // 月，范围 0-11（0 表示一月）
        int tm_year;   // 年，自 1900 年起的年数（例如：2026 年对应 126）
        int tm_wday;   // 星期几，范围 0-6（0 表示星期日）
        int tm_yday;   // 一年中的第几天，范围 0-365（0 表示 1 月 1 日）
        int tm_isdst;  // 夏令时标志，正数表示夏令时，0 表示非夏令时，负数表示未知
    };
   ```  
7. `std::strftime()` 是标准库 `<ctime>` 中定义的函数，**将 `std::tm` 结构体格式化为字符串**。
    - 函数原型：
    ``` c++
        std::size_t strftime(char *str, std::size_t count, const char *format, const std::tm *timer);
    ```  
    - 函数用法：
    ``` c++
        std::time_t t = std::time(nullptr);
        std::tm *tm = std::localtime(&t);
    
        char date[100];
        strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", tm); 
        std::cout << date << std::endl; // 输出 YYYY-MM-DD HH:MM:SS
    ``` 
    - 一些常用的格式说明符： 
     
    | 说明符 | 含义 |  
    | :-- | :-- | 
    | %Y | 四位年 |
    | %y | 两位年（00-99） |
    | %m | 月（01-12） |
    | %d | 日（01-31） |
    | %H | 小时（00-23） |
    | %M | 分钟（00-59） |
    | %S | 秒（00-60） |