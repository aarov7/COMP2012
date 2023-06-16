#include <iostream>
using namespace std;
template <typename T, int N>
void func(T(&arr)[N]) {
cout << "General";
}
template <typename T, int N>
void func(int(&arr)[5]) {
cout << "Specialized";
}
int main() {
int arr[5];
func(arr);
}
