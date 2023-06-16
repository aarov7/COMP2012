#include <iostream>
using namespace std;

class Base 
{ 
 public: 
 Base() = default;
 Base(const Base& other) {
 cout << "Calling copy construcot of Base" << endl;
 }
};

class Derived : public Base 
{
public:
    Derived(){
        cout<<"Default constructor of derived"<<endl;
    }
};


int main() 
{ 
 Derived derived;
 Base base = derived;

 return 0;
}