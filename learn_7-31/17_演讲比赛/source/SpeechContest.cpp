#include "SpeechContest.h"

void SpeechContest::ShowMenu() { //展示菜单
    std::cout << "*****************************" << std::endl;
    std::cout << "***** 欢迎参加演讲比赛！*****" << std::endl;
    std::cout << "****** 1：开始演讲比赛 ******" << std::endl;
    std::cout << "****** 2：查看历史记录 ******" << std::endl;
    std::cout << "****** 3：清空历史记录 ******" << std::endl;
    std::cout << "****** 0：退出比赛程序 ******" << std::endl;
    std::cout << "*****************************" << std::endl;
}

void SpeechContest::Init() { //初始化
    speaker.clear();
    promoter.resize(6);
    m_record.clear();
}

void SpeechContest::SetSpeaker() { //初始化选手
    std::vector<int> numbers(100);
    std::iota(numbers.begin(), numbers.end(), 10000);
    std::shuffle(numbers.begin(), numbers.end(), gen);

    std::string s = "ABCDEFGHIJKL";
    for(int i = 0; i < 12; i++) {
        speaker.push_back(Speaker(numbers[i], s[i]));
    }
}

void SpeechContest::Drawlots(std::vector<Speaker> &group) {
    std::shuffle(group.begin(), group.end(), gen);
    system("pause");
    system("cls");
}

void SpeechContest::Start() { //开始比赛
    //初始化选手
    Init();
    SetSpeaker();

    //第一轮抽签
    std::cout << "各选手正抽签决定分组及演讲顺序..." << std::endl; 
    Drawlots(speaker);
    
    //显示抽签顺序
    std::cout << "------------" << std::endl;
    std::cout << "第 1 小组演讲顺序如下：" << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout << speaker[i].m_id << ' ';
        speaker[i].m_score[0] = getScore();
    }
    std::cout << std::endl;

    std::cout << "第 2 小组演讲顺序如下：" << std::endl;
    for(int i = 6; i < 12; i++) {
        std::cout << speaker[i].m_id << ' ';
        speaker[i].m_score[0] = getScore();
    }
    std::cout << std::endl;
    std::cout << "------------" << std::endl;
    system("pause");
    system("cls");

    // 第一轮 1 组排名
    std::sort(speaker.begin(), speaker.begin() + 6, 
        [](const Speaker &a, const Speaker &b) {
            return a.m_score[0] > b.m_score[0];
        });
    // 第一轮 2 组排名
    std::sort(speaker.begin() + 6, speaker.end(), 
        [](const Speaker &a, const Speaker &b) {
            return a.m_score[0] > b.m_score[0];
        });

    //第一轮比赛
    std::cout << "--------- 第一场比赛正式开始：---------" << std::endl;

    std::cout << "第 1 小组比赛名次：" << std::endl;
    std::for_each(speaker.begin(), speaker.begin() + 6, myPrint(0));

    std::cout << std::endl;

    std::cout << "第 2 小组比赛名次：" << std::endl;
    std::for_each(speaker.begin() + 6, speaker.end(), myPrint(0));

    std::cout << "--------- 第一场比赛正式结束：---------" << std::endl;
    system("pause");
    system("cls");

    
    //第一轮晋级
    merge(speaker.begin(), speaker.begin() + 3, speaker.begin() + 6, speaker.begin() + 9, promoter.begin(), 
        [](const Speaker &a, const Speaker &b) {
            return a.m_score[0] > b.m_score[0];
        }); //merge 必须预留出足够空间（size），而不是容量（capacity）
   
    std::cout << "--------- 第一场晋级选手如下：---------" << std::endl;
    std::for_each(promoter.begin(), promoter.end(), myPrint(0));
    system("pause");
    system("cls");

    //第二轮抽签
    std::cout << "晋级选手正抽签决定演讲顺序..." << std::endl;
    Drawlots(promoter);

    //显示抽签顺序
    std::cout << "------------" << std::endl;
    std::cout << "决胜组演讲顺序如下：" << std::endl;
    std::for_each(promoter.begin(), promoter.end(), 
        [] (Speaker &a) {
            std::cout << a.m_id << ' ';
            a.m_score[1] = getScore();
        });
    std::cout << std::endl;
    std::cout << "------------" << std::endl;
    system("pause");
    system("cls");

    //第二轮决胜组排名
    std::sort(promoter.begin(), promoter.end(), 
        [](const Speaker &a, const Speaker &b) {
            return a.m_score[1] > b.m_score[1];
        }    
    );
   
    //第二轮比赛
    std::cout << "--------- 第二场比赛正式开始：---------" << std::endl;

    std::cout << "决胜组比赛名次：" << std::endl;
    std::for_each(promoter.begin(), promoter.end(), myPrint(1));

    std::cout << "--------- 第二场比赛正式结束：---------" << std::endl;
    std::cout << std::endl;

    //获奖选手
    std::cout << "--------- 本次演讲比赛获奖选手如下：---------" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << title[i] << "：\t";
        promoter[i].showifo(1);
    }
    std::cout << std::endl;

    SaveRecord();

    std::cout << "--------- 本次演讲比赛圆满结束！---------" << std::endl;

    system("pause");
    system("cls");

}

void SpeechContest::SaveRecord() { //保存
    std::ofstream ofs;
    ofs.open("D://code//learn_7-31//17_演讲比赛//build//Record.csv", std::ios::out | std::ios::app);

    int cnt = 0;
    for(std::vector<Speaker>::iterator it = promoter.begin(); it != promoter.begin() + 3 && cnt < 3; it++, cnt++) {
        ofs << title[cnt] << "," 
            << (*it).m_name << ","
            << std::fixed << std::setprecision(2) << (*it).maxScore() << ",";
    }
    ofs << std::endl;

    ofs.close();

    std::cout << "记录保存完毕！" << std::endl;
}

void SpeechContest::ShowRecord() { //读入并展示
    std::ifstream ifs;
    ifs.open("D://code//learn_7-31//17_演讲比赛//build//Record.csv", std::ios::in);

    if(!ifs.is_open()) {
        std::cout << "文件不存在！" << std::endl;
        ifs.close();
        system("pause");
        system("cls");
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof()) {
        std::cout << "文件为空！" << std::endl;
        ifs.close();
        system("pause");
        system("cls");
        return;
    }
    ifs.putback(ch);

    m_record.clear();

    std::string data;
    int num = 0;
    while(ifs >> data) {
        std::vector<std::string> vec;
        int start = 0;
        int pos = data.find(",", start);
        while(pos != -1) {
            std::string tmp = data.substr(start, pos - start);
            vec.push_back(tmp);

            start = pos + 1;
            pos = data.find(",", start);
        }
        m_record.insert(make_pair(num++, vec));
    }
    ifs.close();
   
    for(int i = 0; i < m_record.size(); i++) {
        std::cout << "第 " << i + 1 << " 届比赛记录：" << std::endl
                  << m_record[i][0] << "：" << m_record[i][1] << " 最高得分 " << m_record[i][2] << "\t"
                  << m_record[i][3] << "：" << m_record[i][4] << " 最高得分 " << m_record[i][5] << "\t"
                  << m_record[i][6] << "：" << m_record[i][7] << " 最高得分 " << m_record[i][8] << std::endl;
    }
    system("pause");
    system("cls");
}

void SpeechContest::ClearRecord() { //清空
    std::cout << "确定是否清空历届记录？" << std::endl;
    std::cout << "1：是  0：否" << std::endl;
    int confirm;
    while(std::cin >> confirm) {
        if(confirm == 1 || confirm == 0) break;
        std::cout << "输入有误，请重新输入！" << std::endl;
        std::cout << "1：是  0：否" << std::endl;
    }
    if(confirm) {
        std::ofstream ofs("D://code//learn_7-31//17_演讲比赛//build//Record.csv", std::ios::trunc);
        ofs.close();
        m_record.clear();
        std::cout << "历届记录已清空！" << std::endl;
    } else {
        std::cout << "已取消操作！" << std::endl;
    }
    system("pause");
    system("cls");
}

void SpeechContest::Exit() { //退出
    std::cout << "成功退出比赛程序，欢迎下次使用！" << std::endl;
    system("pause");
    exit(0);
}