#include<iostream>
using namespace std;
class A{
public:
    A(int a){
        this->a=a;
        cout<<"Conversion!"<<endl;
    }
    int a;
};
A func(A x){
    cout<<"Inside func"<<endl;
    return x.a;
}
int main(){
    cout<<func(2).a;
}