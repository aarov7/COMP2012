#include <iostream> 
#include <vector>
#include<algorithm>
#include<string>

using namespace std;

template <typename T>
class Set // Note: Its elements are ALWAYS arranged in ascending order
{  // of their values BEFORE and AFTER any operation
private:
    vector<T> set; // A vector container that stores set elements
public:
    Set() { } // Default constructor
    // Constructor that initializes this "set" with a given array "arr"
    // Note: After initialization, the elements are arranged in ascending order
    Set(T* arr, int size) : set(arr, arr + size) // Using STL's set constructor
    { 
        sort(set.begin(), set.end()); // STL sort() puts elements into ascending order
    } 
    // Compare this "set" and another set "s". Return true if they contain the
    // same set of elements, otherwise return false
    bool operator==(const Set& s) const;
    // Perform union of this "set" and another set "s" and return the resulting set
    // Definition of union operation: Union of two sets is the set that contains
    // all the elements of two sets with no duplicates
    // Note: After union, the elements in the resulting set should be arranged
    // in ascending order
    Set operator+(const Set& s) const;
    // Perform union of this "set" and an "item", and return the resulting set
    // Note: After union, the elements in the resulting set should be arranged
    // in ascending order
    Set operator+(const T& item) const;
    // Update this "set" with union of this "set" and another set "s"
    Set& operator+=(const Set& s);
    // Update this "set" with union of this "set" and an "item"
    Set& operator+=(const T& item);
    // Check whether "item" is in this set.
    // Return true if it is, otherwise return false
    bool contains(const T& item) const;
    // Overload the insertion operator<< for the Set class
    template <typename S>
    friend ostream& operator<<(ostream& os, const Set<S>& s);
};

template<typename T>
bool Set<T>::operator==(const Set<T>& s) const{
    if(set.size()!=s.set.size()){
        return false;
    }
    for(int i=0;i<set.size();i++){
        if(set[i]!=s.set[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
Set<T> Set<T>::operator+(const Set<T>& s) const{
    Set<T> newSet=*this;
    for(int i=0;i<s.set.size();i++){
        if(!newSet.contains(s.set[i])){
            newSet.set.push_back(s.set[i]);
        }
    }
    sort(newSet.set.begin(), newSet.set.end());
    return newSet;
}

template<typename T>
Set<T> Set<T>::operator+(const T& item) const{
    Set<T> newSet=*this;
    if(!newSet.contains(item))
        newSet.set.push_back(item);
    sort(newSet.set.begin(), newSet.set.end());
    return newSet;
}

template<typename T>
Set<T>& Set<T>::operator+=(const Set<T>& s){
    (*this) = (*this + s);
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator+=(const T& item){
    (*this) = (*this + item);
    return *this;
}

template<typename T>
bool Set<T>::contains(const T& item) const{
    for(int i=0;i<set.size();i++){
        if(set[i]==item)
            return true;
    }
    return false;
}

template<typename T> 
ostream& operator<<(ostream& os, const Set<T>& s){
    cout<<"[";
    for(int i=0;i<s.set.size();i++){
        os<<s.set[i]<<((i==s.set.size()-1)?"]":", ");
    }
    return os;
}

int main(){
    string arr1[] = { "Desmond", "Alex", "Brian" };
    Set<string> set1(arr1, sizeof(arr1) / sizeof(string));
    string arr2[] = { "James", "Desmond", "Raymond" };
    Set<string> set2(arr2, sizeof(arr2) / sizeof(string));
    cout << "set1: " << set1 << endl;
    cout << "set2: " << set2 << endl;
    cout << ( (set1 == set2) ? "set1 = set2" : "set1 != set2" ) << endl << endl;
    Set<string> set3 = set1 + set2;
    cout << "After set3 = set1 + set2" << endl;
    cout << "set3: " << set3 << endl << endl;
    set3 += "Cecia";
    cout << "After adding \"Cecia\" to set3" << endl;
    cout << "set3: " << set3 << endl << endl;
    string arr4[] = { "Albert", "Gary" };
    Set<string> set4(arr4, sizeof(arr4) / sizeof(string));
    cout << "set4: " << set4 << endl << endl;
    set3 += set4;
    cout << "After set3 += set4" << endl;
    cout << "set3: " << set3 << endl;
    return 0;
}

