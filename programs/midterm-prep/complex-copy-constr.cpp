#include<iostream>
using namespace std;
class Complex /* File: complex.h */
{
private:
    float real; float imag;
public:
    Complex(float r, float i) {
        real = r; 
        imag = i; 
        cout<<"Constructed!"<<endl;
    }
    Complex(const Complex& other){
        *this=other;
        cout<<"Copied!"<<endl;
    }
    ~Complex(){
        cout<<"Destructed!"<<endl;
    }
    void print() { cout << "( " << real << " , " << imag << " )" << endl; }
    Complex add1(const Complex& x) // Return by value
    {
        std::cout<<"Add 1"<<endl;
        real += x.real; imag += x.imag;
        return (*this);
    }
    Complex* add2(const Complex& x)
// Return by value using pointer
    {
        cout<<"Add 2"<<endl;
        real += x.real; imag += x.imag;
        return this;
    }
    Complex& add3(const Complex& x)
    // Return by reference
    {
        cout<<"Add 3"<<endl;
        real += x.real; imag += x.imag;
        return (*this);
    }
};
int main()
{
    Complex y(3, 4);
    y.print();
    cout << endl << "Return by value" << endl;
    Complex x(1, 2);
    x.print();
    x.add1(y).add1(y).print();
    x.print();
    cout << endl << "Return its pointer by value" << endl;
    Complex* p = x.add2(y);
    p->print();
    cout << endl << "Return by reference" << endl;
    Complex z(1, 2);
    z.print();
    z.add3(y).add3(y).print();
    z.print();
    return 0;
}