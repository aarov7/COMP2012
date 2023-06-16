#include<iostream>

template<typename T>
const T& larger(const T& a, const T& b){
    return ((a>b)?a:b);
}

int main(){
    std::cout<<larger("comp2011","comp2012n");
}