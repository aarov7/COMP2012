#include<iostream>
class Base{
public:
    virtual float print(int a){
        std::cout<<a<<std::endl;
    }
};
class Derived: public Base{
public:
    virtual float print(int a) override{
        std::cout<<a<<std::endl;
    }
}