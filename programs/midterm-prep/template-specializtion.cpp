#include<iostream>
template<typename t>
void func(t A){
    std::cout<<"Normal"<<std::endl;
}
template<>
void func(double A){
    std::cout<<"Specialized"<<std::endl;
}

int main(){
    int a=2;
    int& a_ref=a;
    int
}