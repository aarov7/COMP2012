#include <iostream>
using namespace std;
template <typename T>
void f(T x, T y) {
cout << "Template" << endl;
}
void f(int x, int y) {
cout << "Non-template" << endl;
}
int main() {
f(1, 2);
f('a', 'b');
f(1, 'b');
}
