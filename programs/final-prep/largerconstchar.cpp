#include <iostream>

using namespace std;

 

template <typename T>

const T& larger(const T& a, const T& b) { return (a < b) ? b : a;}

 

int main() {

  const char* m = "microsoft";

  const char* a = "apple";

 

  cout << "Address of the location storing microsoft: "

       << reinterpret_cast<const void*>(m) << endl;

  cout << "Address of the location storing apple: "

       << reinterpret_cast<const void*>(a) << endl;

 

  cout << "Address of m: " << reinterpret_cast<const void*>(&m) << endl;

  cout << "Address of a: " << reinterpret_cast<const void*>(&a) << endl;

 

  cout << larger(a, m) << " is better" << endl;

  cout << larger(&m, &a) << " is better" << endl;

 

  return 0;

}