#include "Speaker.h"

void Speaker::showifo(int index) const {
    std::cout << "编号：" << m_id 
              << "\t选手 " << m_name << " 得分：" << m_score[index] << std::endl;
}

double Speaker::maxScore() const {
    return m_score[0] > m_score[1] ? m_score[0] : m_score[1];
}