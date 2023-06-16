#include<iostream>

class Base{
public:
    Base(){
        std::cout<<"Base default"<<std::endl;
    }
    Base(const Base& o){
        std::cout<<"Base copy"<<std::endl;
    }
    Base(Base&& o){
        std::cout<<"Base move"<<std::endl;
    }
    Base& operator=(const Base& o){
        std::cout<<"Base copy assignment"<<std::endl;
    }
    Base& operator=(Base&& o){
        std::cout<<"Base move assignment"<<std::endl;
    }
    ~Base(){
        std::cout<<"Base destructor"<<std::endl;
    }
};
class Derived: public Base{

};
class Object{
    Base b;
public:
    Object(){
        std::cout<<"Object default"<<std::endl;
    }
    Object(const Object& o){
        std::cout<<"Object copy"<<std::endl;
        *this=o;
    }
    Object(Object&& o){
        std::cout<<"Object move"<<std::endl;
        *this=std::move(o);
    }
    Object& operator=(const Object& o){
        if(this!=&o){
            std::cout<<"Object copy assignment"<<std::endl;
            b=o.b;
        }
        return *this;
    }
    Object& operator=(Object&& o){
        if(this!=&o){
            std::cout<<"Object move assignment"<<std::endl;
            b=std::move(o.b);
        }
        return *this;
    }
    ~Object(){
        std::cout<<"Object destructor"<<std::endl;
    }
};

int main(){
    Object obj(std::move(Object()));
}