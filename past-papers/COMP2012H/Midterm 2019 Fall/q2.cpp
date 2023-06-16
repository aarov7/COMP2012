#include<iostream>
using namespace std;
class Point{
private:
    int x,y;
public:
    Point(int a, int b):
        x(a), y(b){
    }
    const Point& operator =(const Point& b){
        if(this!=&b){
            x=b.x;
            y=b.y;
        }
        return *this;
    }
    const Point& operator +=(const Point& b){
        this->x+=b.x;
        this->y+=b.y;
        return *this;
    }
    friend void print(const Point& p, const Point& q, const Point& r);
};

void print(const Point& p, const Point& q, const Point& r){
    cout << "a = (" << p.x << ", " << p.y << "), "
    << "b = (" << q.x << ", " << q.y << "), "
    << "c = (" << r.x << ", " << r.y << ")" << endl;
}

int main(){
    Point a = { 10, 20 }, b = { 20, 30 }, c = { 30, 40 };
    // Equivalent to a += b += c;
    //plus_equal(a, plus_equal(b, c));
    a+=b+=c;
    print(a, b, c);
    // Your plus_equal function should cause compilation error
    // for the following statement, if it is uncommented.
    // plus_equal(plus_equal(a, b), c);
    // -------------------------------------------------------------------------
    // Equivalent to a = b = c;
    //assign(a, assign(b, c));
    a=b=c;
    print(a, b, c);
    // Your assign function should cause compilation error
    // for the following statement, if it is uncommented.
    // assign(assign(a, b), c);
    // Your assign function shouldn't support self-assignment, i.e. it does not
    // perform assignment of data members for object a for the following.
    a=a;
}