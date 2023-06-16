#include <iostream>
using namespace std;
template <typename T, int& a>
int func(const T& b) {
    cout << "Enter number of " << b << "in the list: ";
    cin >> a;
    return a;
}
int main() {
    const int& c = 10;
    cout << "Number of 10 in the list is: " << func<int, c>(c) << endl;
}
