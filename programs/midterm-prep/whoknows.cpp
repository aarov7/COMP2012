#include <iostream>
using namespace std;
int main() {
    int* const* const p = new int* const(new int);
    **p = 10;
}
