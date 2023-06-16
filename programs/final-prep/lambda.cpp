#include <iostream>
#include<typeinfo>
using namespace std;
int main() {
    int arr[3];
    cout<<typeid(arr).name()<<"\t"<<arr<<endl;
    cout<<typeid(&arr).name()<<"\t"<<&arr<<endl;
    cout<<typeid(&arr[0]).name()<<"\t"<<&arr[0]<<endl;
}
