#include "mywidget.h"
#include <iostream>

#undef main

class Init
{
public:
    explicit Init(){
        int ba = 0;
        int& argc_ = ba;
        app_ = new QApplication(argc_, NULL);
        MyWidget a;
        //a.setFixedSize(100, 50);
        //a.show();
        std::cout << "App start! Wait for key..." << std::endl;
        app_-> exec();
    }
    ~Init() {}

    protected:
    QApplication* app_;
};

int main()
{
 Init i;
}
