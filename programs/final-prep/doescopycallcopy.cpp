#include<iostream>
class Base{
private:
    int a;
public:
    Base(){
        a=0;
        std::cout<<"Base def consntr"<<std::endl;
    }
    Base(const Base& other): a(a){
        std::cout<<"Base copy constr"<<std::endl;
    }
};

class Derived : public Base{
private:
    int b;
public:
    Derived(){
        b=0;
        std::cout<<"Derived def constr"<<std::endl;
    }
    Derived(const Derived& other): Base(other), b(b){
        std::cout<<"Derived copy"<<std::endl;
    }
};

int main(){
    Derived d1;
    Derived d2(d1);
}