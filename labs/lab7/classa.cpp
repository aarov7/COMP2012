#include<iostream>
class A{
    public:
        A(int a): a(a){
            std::cout<<"A"<<std::endl;
        }
        ~A(){
            std::cout<<"~A"<<std::endl;
        }
    private:
        int a;
};

int main(){
    A obj = {8};
}