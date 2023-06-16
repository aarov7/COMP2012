#include <iostream>   // bdptr.cpp
#include <typeinfo>
using namespace std;

class B{};
class D: public B{};   // derived class

int main(){

  B * bptr;
  D d;
  D * dptr;

  dptr = &d; // ok
  bptr = dptr; // ok

  dptr = bptr = nullptr; // No! Invalid conversion from B* to D*
  bptr = dptr = nullptr; // ok, because "=" is right associative returning dptr
  
  bptr = &d; // ok
  dptr = bptr; // No! Invalid conversion from B* to D*
  dptr = &d; // ok

  return 1;
}
  
