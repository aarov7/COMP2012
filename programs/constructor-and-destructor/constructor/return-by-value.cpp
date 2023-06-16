#include <iostream>     /* File: return-by-value.cpp */
#include <cstring> 
using namespace std;
class Word
{
  private:
    int frequency; char* str;
    void set(int f, const char* s)
        { frequency = f; str = new char [strlen(s)+1]; strcpy(str, s); }
  public:
    Word(const char* s, int k = 1) { set(k, s); cout << "conversion\n"; }
    Word(const Word& w) { set(w.frequency, w.str); cout << "copy\n"; }
    void print() const { cout << str << " : " << frequency << endl; }
    Word to_upper_case() const 
    {
        Word x(*this);
        for (char* p = x.str; *p != '\0'; p++) *p += 'A' - 'a';
        return x; //compiler applies copy elision in the return statement
        //this is a compiler optimization, it will be stated in the question whether the compiler does the optimization or not
        //if the compiler didnt optimise here, the copy constructor would be called 3 times
    }
};
int main()
{
    Word movie {"titanic"}; movie.print();
    Word song = movie.to_upper_case(); song.print();
}

