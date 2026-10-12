#include <iostream>
#include <string>
using namespace std;

const int MAX=1000; //通讯录上限人数

struct Contact {
    string name; //姓名
    bool sex; //性别
    string phone; //电话
    string address; //地址
} myConstacts[MAX+10];
int cnt=0; //通讯录人数

void ShowMenu() {
    printf("*****************************\n");
    printf("**** 添加联系人请输入：1 ****\n");
    printf("**** 删除联系人请输入：2 ****\n");
    printf("**** 查找联系人请输入：3 ****\n");
    printf("**** 修改联系人请输入：4 ****\n");
    printf("**** 显示联系人请输入：5 ****\n");
    printf("**** 清空联系人请输入：6 ****\n");
    printf("**** 退出通讯录请输入：0 ****\n");
    printf("*****************************\n");
}

bool CheckContact() { //判断通讯录是否为空
    return (cnt == 0) ? 0 : 1;
}

void ShowContact(int id) { //显示指定联系人信息
    cout << "姓名：" << myConstacts[id].name 
         << "\t性别：" << (myConstacts[id].sex ? "男" : "女") 
         << "\t电话：" << myConstacts[id].phone 
         << "\t地址：" << myConstacts[id].address << endl; //对齐输出
}
void ShowContacts() { //显示所有联系人信息
    for(int i = 1; i <= cnt; i++) {
        ShowContact(i);
    }
    printf("通讯录共计 %d 人\n",cnt);
    system("pause");
    system("cls");
}

void AddContact() { //添加新联系人
    cnt++;

    printf("请输入联系人姓名：\n"); //添加姓名
    cin >> myConstacts[cnt].name;

    int tsex; //添加性别
    printf("请输入联系人性别：\n");
    printf("男请输入：1，女请输入：0\n");
    while(cin >> tsex) {
        if(tsex == 1 || tsex == 0) break;
        printf("输入错误，请重新输入：\n");
        printf("男请输入：1，女请输入：0\n");
    }
    myConstacts[cnt].sex = (bool)tsex;

    printf("请输入联系人电话：\n"); //添加电话
    cin >> myConstacts[cnt].phone;

    printf("请输入联系人地址：\n"); //添加地址
    cin >> myConstacts[cnt].address;

    ShowContact(cnt);
    printf("添加成功！\n");

    system("pause");
    system("cls");
}

int SearchContact(string sname) { //查找指定联系人信息，返回联系人在通讯录中的编号，若未找到则返回 0
    for(int i = 1; i <= cnt; i++) {
        if(myConstacts[i].name == sname) {
            ShowContact(i);
            int confirm;
            printf("确认是否为该联系人？\n");
            printf("是请输入：1，否请输入：0\n");
            while(cin >> confirm) {
                if(confirm == 1 || confirm == 0) break;
                printf("输入错误，请重新输入：\n");
                printf("是请输入：1，否请输入：0\n");
            }
            if(confirm) return i;
            else printf("已取消操作\n");
        }
    }
    return 0;
}

void DeleteContact(string dname) { //删除指定联系人信息
    int id = SearchContact(dname);
    if(id == 0) {
        printf("未找到该联系人，删除失败！\n");
    } else {
        for(int i = id; i < cnt; i++) {
            myConstacts[i] = myConstacts[i + 1];
        }
        cnt--;
        printf("删除成功！\n");
    }
    system("pause");
    system("cls");
}

void ModifyContact(string mname) { //修改指定联系人信息
    int id = SearchContact(mname);
    if(id == 0) {
        printf("未找到该联系人，修改失败！\n");
    } else {
        printf("请输入新的联系人信息：\n");

        printf("请输入联系人姓名：\n"); //修改名字
        cin >> myConstacts[id].name;

        int tsex; //修改性别
        printf("请输入联系人性别：\n");
        printf("男请输入：1，女请输入：0\n");
        while(cin >> tsex) {
            if(tsex == 1 || tsex == 0) break;
            printf("输入错误，请重新输入：\n");
            printf("男请输入：1，女请输入：0\n");
        }
        myConstacts[id].sex = (bool)tsex;

        printf("请输入联系人电话：\n"); //修改电话
        cin >> myConstacts[id].phone;  

        printf("请输入联系人地址：\n"); //修改地址
        cin >> myConstacts[id].address;

        ShowContact(id);
        printf("修改成功！\n");      
    }
    system("pause");
    system("cls");
}

void ClearContact() { //清空通讯录
    cnt = 0;
    printf("已清空通讯录！\n");
    system("pause");
    system("cls");
}

int main() {

    ShowMenu();
    
    int Select = 0; 
    while(scanf("%d", &Select) && Select != 0) {
        switch(Select) {
            case 1: //添加联系人
                AddContact();
                break;

            case 2: { //删除联系人
                if(!CheckContact()) { //判空
                    printf("通讯录为空！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                string dname;
                printf("请输入要删除的联系人姓名：\n");
                cin >> dname;
                DeleteContact(dname);
                break;
            }  

            case 3: { //查找联系人
                if(!CheckContact()) { //判空
                    printf("通讯录为空！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                string sname;
                printf("请输入要查找的联系人姓名：\n");
                cin >> sname;
                int id;
                id=SearchContact(sname);
                if(id == 0) printf("未找到该联系人！\n");
                else {
                    printf("已找到该联系人：\n");
                    ShowContact(id);
                }
                system("pause");
                system("cls");
                break;
            }

            case 4: { //修改联系人
                if(!CheckContact()) { //判空
                    printf("通讯录为空！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                string mname;
                printf("请输入要修改的联系人姓名：\n");
                cin >> mname;
                ModifyContact(mname);
                break;
            }

            case 5: { //显示联系人
                if(!CheckContact()) { //判空
                    printf("通讯录为空！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                ShowContacts();
                break;
            }
            case 6: //清空联系人
                ClearContact();
                break;

            default:
                printf("输入有误，请重新输入！\n");
                system("pause");
                system("cls");
        }

        ShowMenu();
    }

    printf("成功退出通讯录，欢迎下次使用！\n");

    system("pause");

    return 0;
}