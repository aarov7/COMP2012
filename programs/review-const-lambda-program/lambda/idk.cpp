#include <iostream>
using namespace std;
class A {
private:
    int a;
    int b;
    int* p = NULL;
    const double PI;
    int& ref;
public:
A(int a, int bb, int c) : a(a), PI(3.14159), ref(c) {
int b = bb;
p = new int[10];
}
A(int a, int b) : PI(3.14159) {
this->a = a;
this->b = b;
p = new int;
}
~A() {
delete [] p;
}
};
int main() {
A** p = new A*[3];
A obj1;
A obj2(1, 2, 3);
A obj3(4, 5);
p[0] = &obj1;
p[1] = &obj2;
p[2] = &obj3;
return 0;
}