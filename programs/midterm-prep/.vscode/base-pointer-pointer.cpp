
// Wiki Home   >  Inheritance — Proper Inheritance and SubstitutabilityView
// Inheritance — Proper Inheritance and Substitutability  
// Contents of this section:
// Should I hide member functions that were public in my base class?
// Converting Derived* → Base* works okay; why doesn’t Derived** → Base** work?
// Is a parking-lot-of-Car a kind-of parking-lot-of-Vehicle?
// Is an array of Derived a kind-of array of Base?
// Does array-of-Derived is-not-a-kind-of array-of-Base mean arrays are bad?
// Is a Circle a kind-of an Ellipse?
// Are there other options to the “Circle is/isnot kind-of Ellipse” dilemma?
// But I have a Ph.D. in Mathematics, and I’m sure a Circle is a kind of an Ellipse! Does this mean Marshall Cline is stupid? Or that C++ is stupid? Or that OO is stupid?
// Perhaps Ellipse should inherit from Circle then?
// But my problem doesn’t have anything to do with circles and ellipses, so what good is that silly example to me?
// How could “it depend”??!? Aren’t terms like “Circle” and “Ellipse” defined mathematically?
// If SortedList has exactly the same public interface as List, is SortedList a kind-of List?
// Should I hide member functions that were public in my base class?  
// Never, never, never do this. Never. Never!

// Attempting to hide (eliminate, revoke, privatize) inherited public member functions is an all-too-common design error. It usually stems from muddy thinking.

// (Note: this FAQ has to do with public inheritance; private and protected inheritance are different.)

// Converting Derived* → Base* works okay; why doesn’t Derived** → Base** work?  
// Because converting Derived** → Base** would be invalid and dangerous.

// C++ allows the conversion Derived* → Base*, since a Derived object is a kind of a Base object. However trying to convert Derived** → Base** is flagged as an error. Although this error may not be obvious, it is nonetheless a good thing. For example, if you could convert Car** → Vehicle**, and if you could similarly convert NuclearSubmarine** → Vehicle**, you could assign those two pointers and end up making a Car* point at a NuclearSubmarine:
#include<iostream>
using namespace std;
class Vehicle {
public:
  virtual ~Vehicle() { }
  virtual void startEngine() = 0;
};
class Car : public Vehicle {
public:
  virtual void startEngine(){
    cout<<"Car::Engine()"<<endl;
  }
  virtual void openGasCap(){
    cout<<"Car::Gas()"<<endl;
  }
};
class NuclearSubmarine : public Vehicle {
public:
  virtual void startEngine(){
    cout<<"Sub::Engine()"<<endl;
  }
  virtual void fireNuclearMissile(){
    cout<<"Sub::Missile()"<<endl;
  }
};
int main()
{
  Car   car;
  Car*  carPtr = &car;
  Car** carPtrPtr = &carPtr;
  Vehicle** vehiclePtrPtr = reinterpret_cast<Vehicle**>(carPtrPtr);  // This is an error in C++
  NuclearSubmarine  sub;
  NuclearSubmarine* subPtr = &sub;
  *vehiclePtrPtr = subPtr;
  // This last line would have caused carPtr to point to sub !
  carPtr->openGasCap();  // This might call fireNuclearMissile()!
  // ...
}