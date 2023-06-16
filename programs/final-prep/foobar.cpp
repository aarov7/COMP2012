 #include <iostream>
 #include <cstring>
 using namespace std;

 class Foo
 {
 public:
 Foo()
 {
 a = new char[9];
 strcpy(a, "comp2012");
 c = 100;
 }

 ~Foo() { delete a; }
 void set_b(int b) { Foo::b = b; }
 void set_c(int c) { this->c{c}; }
 int get_b() const { return b; }
 int get_c() const { return c; }

 private:
 const char* a;
 int b{10}, c;
 };

 class Bar
 {
 public:
 Bar() { obj = new Foo(); }
 ~Bar() { delete obj; }
 const Foo& get_obj() const { return *obj; }
 void modify(int b) const { obj->set_b(b); }

 private:
 Foo* obj;
 };

 void operate(Bar bar) { bar.modify(10); }

 int main()
 {
 Bar bar;
 Foo* foo = &bar.get_obj();
 operate(bar);
 return 0;
 }