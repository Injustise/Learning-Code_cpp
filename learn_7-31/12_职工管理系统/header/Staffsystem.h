#pragma once

#include <iostream>
#include <string>
#include "Staff.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include "Idtime.h"
#include <fstream>

using namespace std;

class Staffsystem {
    public:
        int m_num;
        Staff **StaffArray;
        bool FileIsEmpty;
    public:
        Staffsystem(); //构造函数
        ~Staffsystem(); //析构函数
        bool CheckEmpty(); //判空
        void ExitSystem(); //退出系统
        void ShowMenu(); //展示系统菜单
        void ShowStaff(); //展示职工列表
        void AddStaff(); //添加职工
        int FindStaff(); //查找职工
        void DeleteStaff(); //删除职工
        void ModifyStaff(); //修改职工
        void SortStaff(); //按号排序
        void ClearList(); //清空列表
        void Save(); //写入文件
        int GetListNum(); //读出文件
        void Init(); //文件初始化
};