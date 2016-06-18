#include <iostream>

using namespace std;

class Base
{
public:
    int b;
    void Display()
    {
        cout<<"Base: Non-virtual display."<<endl;
    };
    virtual void vDisplay()
    {
        cout<<"Base: Virtual display."<<endl;
    };
};

class Derived : public Base
{
public:
    int d;
    void Display()
    {
        cout<<"Derived: Non-virtual display."<<endl;
    };
    virtual void vDisplay()
    {
        cout<<"Derived: Virtual display."<<endl;
    };
};

int main()
{
    Base ba;
    Derived de;

    Base* b_ptr = &ba;


    b_ptr->Display();
    b_ptr->vDisplay();

    ba.Display();
    ba.vDisplay();
    de.Display();
    de.vDisplay();

    return 0;
};