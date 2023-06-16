//compile with g++ -std=c++11 -Werror
#include<iostream>
using namespace std;
class AbstractBase {
public:
    AbstractBase(){ func();}
    virtual void func() = 0;  // Declare pure virtual function
};

// Define pure virtual function
void AbstractBase::func() {
    cout << "This is a pure virtual function in AbstractBase.\n";
}

class Derived : public AbstractBase {
public:
    void func() override {
        AbstractBase::func();  // Call base class version
        cout << "This is Derived's override of the function.\n";
    }
};

int main() {
    Derived d;
    d.func();  // Calls Derived::func(), which also calls AbstractBase::func()
    return 0;
}
