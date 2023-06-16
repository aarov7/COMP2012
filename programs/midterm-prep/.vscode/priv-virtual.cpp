#include<iostream>
using namespace std;
class Base{
    public:
    virtual void func(){
        cout<<"Base";
    }
};
class Derived: public Base{
    virtual void func(){
        cout<<"dervied";
    }
};
int main(){
    Base* bp=new Derived;
    bp->func();
}