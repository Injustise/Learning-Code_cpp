#pragma once

#include <iostream>
#include <string>

class Speaker {
public:
    int m_id;
    char m_name;
    double m_score[2];
public:
    Speaker() {}
    Speaker(int id, char name) : 
        m_id(id), m_name(name) {}
    void showifo(int index) const;
    double maxScore() const;
};