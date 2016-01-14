#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv[]) {
    char * path = argv[1];
    ifstream fin(path);
    if(!fin) {
        cout << "Wrong path!" << endl;
        return 0;
    }
    ofstream fout("Without comments.cpp");
    bool flag = true;
    bool flag2 = false;
    while(!fin.eof()) {
        char * s = new char[1024];
        char * s1 = new char[1024];;
        streamsize n = 1024;
        fin.getline(s, n);
        int k = 0;
        flag2 = true;
        while( (s[k] != '\0') ) {
            if(s[k] == '\"') {
                flag2 = !flag2;
            }
            if( (s[k] == '/') && (s[k + 1] == '*') && (flag2) ) {
                flag = false;
            }
            if( (s[k] == '/') && (s[k + 1] == '/') && (flag2) ) {
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
            if( (strlen(s1) == 0) && (strlen(s) != 0) ) {

            }
            else {
                fout << s1 << endl;
            }
    }
    fin.close();
    fout.close();
    return 0;
}
