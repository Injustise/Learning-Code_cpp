#include "Staffsystem.h"

Staffsystem::Staffsystem() { //构造函数初始化
    this->m_num = 0;
    this->StaffArray = nullptr;

    ifstream ifs("D:\\code\\learn_7-31\\12_职工管理系统\\build\\Stafflist.txt", ios::in);

    //文件不存在
    if(!ifs.is_open()) { 
        return;
    }
   
    //文件为空
    char ch;
    ifs >> ch;
    if(ifs.eof()) { 
        ifs.close();
        return;
    }

    //文件不为空
    int initNum = this->GetListNum();
    this->m_num = initNum;
    this->StaffArray = new Staff*[initNum];
    this->Init();

} 

Staffsystem::~Staffsystem() { //析构函数释放堆区内存
    if(this->StaffArray != nullptr) {
        delete[] this->StaffArray;
        this->StaffArray = nullptr;
    }
}

bool Staffsystem::CheckEmpty() { //判空
    return this->m_num;
}

void Staffsystem::ExitSystem() { //退出系统
    cout << "成功退出职工管理系统，欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void Staffsystem::ShowMenu() { //展示系统菜单
    cout << "***********************************" << endl;
    cout << "****** 欢迎使用职工管理系统！******" << endl;
    cout << "****** 添加职工信息请输入：1 ******" << endl;
    cout << "****** 显示职工信息请输入：2 ******" << endl;
    cout << "****** 删除职工信息请输入：3 ******" << endl;
    cout << "****** 修改职工信息请输入：4 ******" << endl;
    cout << "****** 查询职工信息请输入：5 ******" << endl;
    cout << "****** 按照编号排序请输入：6 ******" << endl;
    cout << "****** 清空所有文档请输入：7 ******" << endl;
    cout << "****** 退出管理系统请输入：0 ******" << endl;
    cout << "***********************************" << endl;
}

void Staffsystem::ShowStaff() { //展示职工列表
    if(!this->CheckEmpty()) {
        cout << "职工列表为空！" << endl;
        system("pause");
        system("cls");
        return;
    }

    for(int i = 0; i < this->m_num; i++) {
        this->StaffArray[i]->showifo();
    }

    system("pause");
    system("cls");
}

void Staffsystem::AddStaff() { //添加职工
    cout << "请输入添加职工数量：" << endl;
    int addNum;
    while(cin >> addNum) {
        if(addNum > 0) break;
        cout << "输入有误，请重新输入！" << endl;
    }


    int newNum = this->m_num + addNum;
    Staff **NewArray = new Staff* [newNum];
 
    
    for(int i = 0; i < this->m_num; i++) {
        NewArray[i] = this->StaffArray[i];
    }
    delete[] this->StaffArray;
    this->StaffArray = nullptr;

    int pos;
    string id, name;
    Staff *worker = nullptr;
    for(int i = 0; i < addNum; i++) {
        id = generateTimeID();

        cout << "请输入第 " << i + 1 << " 位添加职工的姓名：" << endl;
        cin >> name;

        cout << "请输入第 " << i + 1 << " 位添加职工的职位：" << endl;
        cout << "1：老板  2：经理  3：普通员工" << endl;

        while(cin >> pos) {
            if(pos == 1) {
                worker = new Boss(id, name, pos);
                break;
            }
            else if(pos == 2) {
                worker = new Manager(id, name, pos);
                break;
            }
            else if(pos == 3) {
                worker = new Employee(id, name, pos);
                break;
            } 
            else cout << "输入有误，请重新输入！" << endl;           
        }
        NewArray[this->m_num + i] = worker;
    }
        
    this->StaffArray = NewArray;
    this->m_num = newNum;

    
    cout << "成功添加 " << addNum << " 位职工！" << endl;
    this->Save();

    system("pause");
    system("cls");
}

int Staffsystem::FindStaff() { //查找职工
    cout << "请选择查找方式：" << endl;
    cout << "1：编号查找  2：姓名查找" << endl;
    int confirm;
    while(cin >> confirm) {
        if(confirm == 1 || confirm == 2) break;
        cout << "输入有误，请重新输入！" << endl;
        cout << "1：编号查找  2：姓名查找" << endl;
    }

    if(confirm == 1) {
        cout << "请输入查找职工的编号：" << endl;
        string id;
        while(cin >> id && id.size() != 9) {
            cout << "输入有误，请重新输入！" << endl;
        }
        for(int i = 0; i < this->m_num; i++) {
            if(this->StaffArray[i]->m_id == id) return i;
        }
        return -1;
    } 
    else {
        cout << "请输入查找职工的姓名：" << endl;
        string name;
        cin >> name;
        for(int i = 0; i < this->m_num; i++) {
            if(this->StaffArray[i]->m_name == name) {
                cout << "确认是否为该职工？" << endl;
                this->StaffArray[i]->showifo();
                cout << "1：是  0：否" << endl;
                int confirm;
                while(cin >> confirm) {
                    if(confirm == 1 || confirm == 0) break;
                    cout << "输入有误，请重新输入！" << endl;
                    cout << "1：是  0：否" << endl;
                }
                if(confirm) return i;
                else cout << "继续查找中..." << endl;
            }
        }
        return -1; 
    }             
}

void Staffsystem::DeleteStaff() { //删除职工
    if(!this->CheckEmpty()) {
        cout << "职工列表为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    
    int i = Staffsystem::FindStaff();

    if(i == -1) {
        cout << "查无此人，删除失败！" << endl;
    } else {
        delete StaffArray[i]; //释放要被删除的堆区内存，防止内存泄漏
        for(int j = i; j < this->m_num-1; j++) {
            this->StaffArray[j] = this->StaffArray[j + 1];
        }
        this->StaffArray[m_num - 1] = nullptr; //最后一个指针置空，防止野指针
        this->m_num--;
        cout << "删除成功！" << endl;
        this->Save();
    }

    system("pause");
    system("cls");
}

void Staffsystem::ModifyStaff() { //修改职工
    if(!this->CheckEmpty()) {
        cout << "职工列表为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    
    int i = Staffsystem::FindStaff();

    if(i == -1) {
        cout << "查无此人，修改失败！" << endl;
    } else {
        cout << "请输入修改后职工的姓名：" << endl;
        cin >> this->StaffArray[i]->m_name;

        cout << "请输入修改后职工的职位：" << endl;
        cout << "1：老板  2：经理  3：普通员工" << endl;
        int pos;
        while(cin >> pos) {
            if(pos == 1 || pos == 2 || pos == 3) break;
            cout << "输入有误，请重新输入！" << endl; 
        }
        this->StaffArray[i]->m_position = pos; 

        StaffArray[i]->showifo();
        cout << "修改成功！" << endl;
        this->Save();
    }

    system("pause");
    system("cls");
}

void Staffsystem::SortStaff() { //按号排序
    cout << "功能尚未完善！" << endl;

    system("pause");
    system("cls");
}

void Staffsystem::ClearList() { //清空列表
    if(!this->CheckEmpty()) {
        cout << "职工列表已为空！" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "确定是否清空？" << endl;
    cout << "1：是  0：否" << endl;
    int confirm;
    while(cin >> confirm) {
        if(confirm == 1 || confirm == 0) break;
        cout << "输入有误，请重新输入！" << endl;
        cout << "1：是  0：否" << endl;
    }

    if(confirm) {
        ofstream ofs("D:\\code\\learn_7-31\\12_职工管理系统\\build\\Stafflist.txt", ios::trunc);
        ofs.close();

        if(this->StaffArray != nullptr) { //释放要被清空的堆区内存，防止内存泄漏
            for(int i = 0; i < this->m_num; i++) {
                delete this->StaffArray[i]; //这里释放的是数组元素 Staff* 的堆区内存
            }
            delete[] this->StaffArray; //而这里释放的是数组本身 Staff** 的堆区内存
            this->StaffArray = nullptr;
            this->m_num = 0;
        }
        cout << "职员列表已清空！" << endl;
    } else {
        cout << "已取消操作！" << endl;
    }

    system("pause");
    system("cls");
}

void Staffsystem::Save() { //写入文件
    ofstream ofs("D:\\code\\learn_7-31\\12_职工管理系统\\build\\Stafflist.txt", ios::out);
    
    for(int i = 0; i < this->m_num; i++) {
        ofs << this->StaffArray[i]->m_id << " " 
            << this->StaffArray[i]->m_name << " "
            << this->StaffArray[i]->m_position << endl;
    }

    ofs.close();
}

int Staffsystem::GetListNum() { //读出文件
    ifstream ifs("D:\\code\\learn_7-31\\12_职工管理系统\\build\\Stafflist.txt", ios::in);
    
    int pos;
    string id, name;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> pos) num++;

    ifs.close();

    return num;
}

void Staffsystem::Init() { //文件初始化
    ifstream ifs("D:\\code\\learn_7-31\\12_职工管理系统\\build\\Stafflist.txt", ios::in);

    int pos;
    string id, name;
    Staff *worker = nullptr;
    int cnt = 0;
    while(ifs >> id && ifs >> name && ifs >> pos) {
        switch(pos) {
            case 1: {
                worker = new Boss(id, name, pos);
                break;
            }
            case 2: {
                worker = new Manager(id, name, pos);
                break;
            }
            case 3: {
                worker = new Employee(id, name, pos);
                break;
            }
        }
        this->StaffArray[cnt++] = worker;
    }   
}