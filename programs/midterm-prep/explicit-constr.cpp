#include<iostream>
using namespace std;
class tester{
    int a;
public:
    tester(int x){
        a=x;
        cout<<"Created"<<endl;
    }
    tester(const tester& other){
        *this=other;
        cout<<"Copiedx"<<endl;
    }
    ~tester(){
        cout<<"Deleted"<<endl;
    }
    tester add(tester other){
        a+=other.a;
        return (*this);
    }
    int getA(){
        return a;
    }
};
int main(){
    tester obj=2;
    obj.add(3).add(2);
    cout<<obj.getA()<<endl;
    return 0;
}