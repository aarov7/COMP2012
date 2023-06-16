#include<iostream>
#include<typeinfo>
class Base{
public:
    virtual void func(){}
};
class Derived: public Base{
public:
    void func(){}
};
int main(){
    Base* bp=new Derived;
    std::cout<<typeid(*bp).name();
}