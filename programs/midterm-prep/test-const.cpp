#include<iostream>
int main(){
    const int a=2;
    int* p;
    const int** p1=&p;
    *p1=&a;
    *p=5;
}