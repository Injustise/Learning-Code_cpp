### 一些笔记
1.  C++ 的 `static_cast<unsigned>(expr)` 和 C 风格的强制转换 `(unsigned)expr` 对比：在基本数值类型转换（如 int → unsigned、double → int）时，功能上完全相同，但区别在于**安全性、可检查性和使用范围**上。
    - `static_cast` 只执行明确定义的、相对安全的转换，并在编译时进行检查，拒绝不合理的转换  
    - `static_cast<unsigned>()` 在代码中非常醒目，一眼就能看出这是一次类型转换，并且目标类型明确，而 C 风格 `(unsigned)` 可能与其他语法混淆，并且在大型代码库中难以搜索。