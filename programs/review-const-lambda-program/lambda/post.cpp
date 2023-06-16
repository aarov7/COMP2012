#include<iostream>
using namespace std;
int func(int x){
    cout<<x;
}
int main(){
    int a=2;
    func(a++);
    cout<<a<<endl;
}