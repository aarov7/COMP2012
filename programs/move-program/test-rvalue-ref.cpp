#include<iostream>
int main(){
    int a=2;
    int& b=a;
    int&& c= 3;
    const int& f=c;
    c=a;
    int&& d=5;
    d=7;
    d=b;
}