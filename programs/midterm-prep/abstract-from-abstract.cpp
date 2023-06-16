#include <iostream>
using namespace std;

class B {
public:
    virtual void print() const = 0;
    B() { cout << "Make B"<<endl; }
    ~B() { cout << "~B"; }
};
class C : public B {
public:
    virtual void print() const = 0;
    C() { cout << "Make C"<<endl; }
    ~C() { cout << "~C"; }
};
int main() {
    C* c = new C;
    delete c;
}