#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include "Speaker.h"
#include "getScore.h"
#include "myPrint.h"

class SpeechContest {
public:
    std::vector<Speaker> speaker;
    std::vector<Speaker> promoter;
    std::string title[3] = {"冠军", "亚军", "季军"};
    std::map<int, std::vector<std::string>> m_record;
public:
    void ShowMenu();
    void Init();
    void Start();
    void SetSpeaker();
    void Drawlots(std::vector<Speaker> &group);
    void SaveRecord();
    void ShowRecord();
    void ClearRecord();
    void Exit();
};