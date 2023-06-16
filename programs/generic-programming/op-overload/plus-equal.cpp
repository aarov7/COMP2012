#include<iostream>
using namespace std;

class MyInt{
    int a;
    friend MyInt& operator+=(MyInt& obj1, MyInt& obj2);
    friend ostream& operator<<(ostream& os, const MyInt& obj);
    public:
    MyInt(int a): a(a){}
};
MyInt& operator+=(MyInt& obj1, MyInt& obj2){
    obj1.a+=obj2.a;
    return obj1;
}
ostream& operator<<(ostream& os, const MyInt& obj){
    return os<<obj.a;
}
int main(){
    MyInt obj1(5), obj2(6);
    cout<<(obj1+=obj2)<<endl;
    cout<<obj1;
}