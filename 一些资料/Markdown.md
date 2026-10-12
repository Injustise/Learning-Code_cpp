# Markdown 使用指南
## 一、基本语法
1. **标题**
    #一级标题
    ##二级标题
    ...
2. **引用**
    > 引用文段
3. **列表**
    1. 无序列表
    - 列表1
    + 列表2
    * 列表3
    2. 有序列表
    3. 嵌套
    4. Todolist
        - [ ] 吃
        - [ ] 喝
        - [ ] 玩
        - [ ] 乐   
4. **表格**
    | 左对齐 | 居中对齐 | 右对齐 |
    | :--- | :---: | ---: |
    | left | middle | right |
5. **段落**
    1. 分割线： ***
    *** 
    2. 字体
        | 字体 | 代码 |
        | :--: | :--: |
        | *斜体* | * * |
        | **粗体** | ** ** |
        | ***粗斜体*** | *** *** |
        | ==高亮== | == == |
        | <u>下划线<u/> | ` <u> <u/> ` |
        | ~~删除~~ | ~~ ~~ |
    3. 注脚 
        一键三连[^1]！
6. **代码**
    ``` 
    #include <iostream>
    using namespace std;

    int main() {

        printf("Hello World!\n");

        system("pause");

        return 0;
    }
    ```
    ` printf("Hello World!\n"); `
7. **超链接**
    -  [B站]：https://www.bilibili.com/
    -  [点击B站][B站大学]
8. **图片**
    - 使用图床保存图片
      [路过图床]：https://imgchr.com/
    - 用 Markdown 语法插入
      [![pm5bZQJ.md.jpg](https://s41.ax1x.com/2026/08/03/pm5bZQJ.md.jpg)](https://imgchr.com/i/pm5bZQJ)
## 其他操作
- **插入Latex公式**
    - 行内插入 $f(x)=ax^2+bx+c$
    - 块内插入 
    $$
       C_{n}^{m}=\frac{n!}{m!(n-m)!}
    $$
     
[B站大学]:https://www.bilibili.com/
[^1]:下次一定 Ciallo～ (∠・ω< )⌒★