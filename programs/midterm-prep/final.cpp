#include<iostream>
int& func(int& a){
    std::cout<<"called"<<std::endl;
    return a;
}
int main(){
    int a=2;
    int& haha=a;
    func(a)+=2;
    std::cout<<func(a);
}