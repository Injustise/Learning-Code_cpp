#include "Manager.h"

Manager::Manager(string id, string name, int pos) {
    m_id = move(id);
    m_name = move(name);
    m_position = pos; 
}

void Manager::showifo() {
    cout << "职工编号：" << m_id 
         << "\t姓名：" << m_name 
         << "\t职位：" << "经理" << endl;
}