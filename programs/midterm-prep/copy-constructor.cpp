#include<iostream>
class A{
public:
    A(){
        std::cout<<"Default"<<std::endl;
    }
    A(const A& a){
        std::cout<<"Copy"<<std::endl;
    }
};
int main(){
    A obj;
    A* newA =new A;
    (*newA)=obj;
}