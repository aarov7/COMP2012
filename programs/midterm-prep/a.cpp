#include <iostream>
using namespace std;
class B; // Forward declaration of class B
class A: public B
{
public:
A() { cout << "A's constructor" << endl; }
~A() { cout << "A's destructor" << endl; }
};
class B : public A
{
public:
B() { cout << "B's constructor" << endl; }
~B() { cout << "B's destructor" << endl; }
};
int main() { A a; B b; return 0; }
