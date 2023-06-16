#include<iostream>
int add(const int& val){
    std::cout<<"1"<<std::endl;
    val+=2;
    return val;
}
int add(const int val){
    std::cout<<"2"<<std::endl;
    val+=2;
    return val;
}
int main(){
    std::cout<<add(2)<<std::endl;
}