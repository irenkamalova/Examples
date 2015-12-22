#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("How use destructor correctly.cpp");
    ofstream fout("New.cpp");
    bool flag;
    while(!fin.eof()) {
        char * s = new char[1024];
        char * s1 = new char[1024];;
        streamsize n = 1024;
        fin.getline(s, n);
        int k = 0;
        while( (s[k] != '\0') ) {
            if( (s[k] == '/') && (s[k + 1] == '*') ) {
                flag = false;
            }
            if( (s[k] == '/') && (s[k + 1] == '/') ) {
                break;
            }
            else {
                if(flag)
                    s1[k] = s[k];
            }
            if( (s[k] == '*') && (s[k + 1] == '/') ) {
                flag = true;
            }
            k++;
        }
        if(flag)
            fout << s1 << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
