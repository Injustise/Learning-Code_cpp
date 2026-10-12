### 一些笔记
1. - `case` 本质是跳转标签，当执行 `switch` 时，程序会直接跳转到匹配的 `case` 位置。
   - 如果你的某个 `case` 下面定义了变量，可能会出现以下报错： 
    `error: jump to case label crosses initialization`（跳转到 `case` 标签绕过了初始化）
    这是因为 C++ 语法**严禁通过跳转绕过变量的初始化**。
   - 所以习惯把某个 `case` 里的代码**用大括号 `{}` 包起来**，这样变量就只在这个作用域内生效，既安全又能彻底解决这个报错问题。
2. - `printf` 不能直接输出 `string` 类型
   - `printf` 的 `%s` 是为字符数组 `char[]` 或字符指针 `char*` 设计的。
   - 可以**调用 `.c_str()`** 将 `string` 转化为 `char[]`，这样就可以用 `printf` 进行输出了：    
      ``` c++
      string s = "Hello World"；
      printf("%s\n", s.c_str());
      ```  
      当然你也可以**直接用 `std::cout << s;`**，它原生支持 `std::string`，不需要手动转换，而且类型安全。