#include <iostream>
using namespace std;

void func1(double f) {
    f = f + 1;
}

void func1(float f) {
    f = f - 1;
}

void func2(unsigned char c) {
    cout << c;
}

void func2(char c) {
    cout << c;
}

int func3(int a, int b) {
    cout << a + b << endl;
}

int func3(int a, int &b) {
    cout << a - b << endl;
}

int main() {

    double d = 1;
    float f = 2;
    func1(d);
    func1(f);
    int i = 3;
    //func1(i); // Compilation error: call of overloaded ‘func1(int&)’ is ambiguous
    //func1(10); // Compilation error: call of overloaded ‘func1(int)’ is ambiguous

    func2('c');
    func2(86); // Compilation error: call of overloaded ‘func2(int)’ is ambiguous

    func3(10, 11);
    int a = 15, b = 10;
    func3(a, b); // Compilation error: call of overloaded ‘func3(int&, int&)’  is ambiguous


    return 0;
}
