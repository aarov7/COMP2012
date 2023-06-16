#include<iostream>
template <typename T>
T* func() { return new T; }
int main(){
    const int* a = new const int;
    const int* const* b = &a;
}