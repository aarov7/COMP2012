template <typename T>
class A {
public:
    T funcWithSyntaxError() {
        int a = 10;
        int* p = a; // This line has syntax error
        return a;
    }
};
int main(){
    A<int> obj;
}