#include <iostream>
#include <string>

using namespace std;

//抽象零件
class CPU {
public:
    virtual void calculate() = 0;
};
class GPU {
public:
    virtual void display() = 0;
};
class Memory {
public:
    virtual void storage() = 0;
};

//Intel 厂商
class IntelCPU : public CPU { 
public:
    void calculate() {
        cout << "Intel 的 CPU 正常计算" << endl;
    }    
};
class IntelGPU : public GPU {
public:
    void display() {
        cout << "Intel 的 GPU 正常显示" << endl;
    }    
};
class IntelMemory : public Memory {
public:
    void storage() {
        cout << "Intel 的 Memory 正常存储" << endl;
    }    
};

//Lenovo 厂商
class LenovoCPU : public CPU {
public:
    void calculate() {
        cout << "Lenovo 的 CPU 正常计算" << endl;
    }    
};
class LenovoGPU : public GPU {
public:
    void display() {
        cout << "Lenovo 的 GPU 正常显示" << endl;
    }    
};
class LenovoMemory : public Memory {
public:
    void storage() {
        cout << "Lenovo 的 Memory 正常存储" << endl;
    }    
};


class Computer { 
protected: //零件接口（抽象父类指针）
    CPU *m_cpu; 
    GPU *m_gpu;
    Memory *m_memory;
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory) : m_cpu(cpu), m_gpu(gpu), m_memory(memory) {} //接入具体零件（重写子类指针）
    ~Computer() { //重载析构，释放堆区内存
        if(m_cpu != nullptr) {
            delete m_cpu;
            m_cpu = nullptr;
        }
        if(m_gpu != nullptr) {
            delete m_gpu;
            m_gpu = nullptr;
        }
        if(m_memory != nullptr) {
            delete m_memory;
            m_memory = nullptr;
        }
        cout << "computer 的析构函数" << endl;
    }
    void work() {
        m_cpu->calculate();
        m_gpu->display();
        m_memory->storage();
    }

};

void test() {
    CPU *icpu = new IntelCPU; //选择具体厂商零件
    GPU *igpu = new IntelGPU;
    Memory *imemory = new IntelMemory;
    CPU *lcpu = new LenovoCPU; //选择具体厂商零件
    GPU *lgpu = new LenovoGPU;
    Memory *lmemory = new LenovoMemory;

    cout << "我的第一台电脑：" << endl;
    Computer *mycomputer = new Computer(icpu, igpu, imemory); //接入 Intel 厂商零件
    mycomputer->work();
    cout << "before delete" << endl;
    delete mycomputer; //释放 mycomputer 堆区内存，触发重载析构函数
    cout << "after delete" << endl;

    cout << "------------------------" << endl;
    
    cout << "我的第二台电脑：" << endl;
    mycomputer = new Computer(lcpu, lgpu, lmemory); //接入 Lenovo 厂商零件
    mycomputer->work();
    delete mycomputer; //释放 mycomputer 堆区内存，触发重载析构函数
}

int main() {

    test();

    system("pause");

    return 0;
}