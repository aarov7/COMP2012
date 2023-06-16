#include <iostream>
using namespace std;
class A {
public:
    A() { cout<<"Make A"<<endl;}
    ~A() { cout << "~A"; }
};
class B {
public:
    B() { cout << "Make B"<<endl; }
    ~B() { cout << "~B"; }
};
class C : public B {
public:
    C() { cout << "Make C"<<endl; }
    ~C() { cout << "~C"; }
    A a;
};
int main() {
    C* c = new C;
    delete c;
}