#include<iostream>
template<typename T,int N>
void func(T (&arr)[N]){
   std::cout<<N<<std::endl; 
}

int main(){
    int arr[5];
    std::cout<<sizeof(arr)/sizeof(int)<<std::endl; 
    func(arr);
}