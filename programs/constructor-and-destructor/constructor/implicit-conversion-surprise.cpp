#include <iostream>     /* File: implicit-conversion-surprise.cpp */
#include <cstring> 
using namespace std;
class Word
{
  private:
    int frequency; char* str;
  public:
    Word(char c)
        { frequency = 1; str = new char[2]; str[0] = c; str[1] = '\0';
          cout << "call implicit char conversion\n"; }
    Word(const char* s)
        { frequency = 1; str = new char [strlen(s)+1]; strcpy(str, s);
          cout << "call implicit const char* conversion\n"; }
    Word(const Word& word){
      cout<<"Copied"<<endl;
      str=new char[strlen(word.str)+1];
      strcpy(str,word.str);
      frequency=word.frequency;
    }
    ~Word(){
      cout<<"deleted"<<endl;
      delete[] str;
    }
    void print() const { cout << str << " : " << frequency << endl; }
};

void print_word(Word x) { x.print(); }
int main() { print_word("Titanic"); print_word('A'); return 0; }
