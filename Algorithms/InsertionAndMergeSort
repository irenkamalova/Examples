// For unit-test:
//#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

using namespace std;

//#define N 100

template<class ArrayType>
class my_array {
    ArrayType * a;
    int size;
public:

    my_array(int N) {
        a = new ArrayType[N];
        size = N;
    }

    static ArrayType * random_array(int N) {

        srand( time(NULL) );
        ArrayType *r_array = new ArrayType[N];
        for(int i = 0; i < N; i++) {
            r_array[i] = rand() % 100 + 1;
        }
        return r_array;
    }

    void init(ArrayType *r_array) {
        for(int i = 0; i < size; i++) {
            a[i] = r_array[i];
        }
    }

    void show() {
        for(int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void insert_sort() {
        for(int i = 1; i < size; i++) {
            ArrayType key = a[i];
            int j = i - 1;
            while((j >= 0)&&(a[j] > key)) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
    }

    void reverse_insert_sort() {
        for(int i = 1; i < size; i++) {
            ArrayType key = a[i];
            int j = i - 1;
            while((j >= 0)&&(a[j] < key)) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
    }

    ArrayType linear_search(ArrayType v) {
        for(int i = 1; i < size; i++) {
            if( a[i] == v) {
                return i;
            }
        }
        return NULL;
    }

    void reverse_merge(int p, int q, int r) {
        ArrayType buffer;
        ArrayType a2[r - p + 1];
        int i = p, j = q + 1, k = 0;
        while( (i <= q) && (j <= r) ) {
            ArrayType s1 = a[i], s2 = a[j];
            if(a[i] > a[j]) {
                a2[k] = a[i];
                i++;
                k++;
            }
            else {
                a2[k] = a[j];
                j++;
                k++;
            }
        }
        while( i <= q  ) {
            a2[k] = a[i];
            i++;
            k++;
        }
        while( j <= r ) {
            a2[k] = a[j];
            j++;
            k++;
        }
        k = 0;
        for(int i = p; i <= r; i++) {
            a[i] = a2[k];
            k++;
        }
    }

    void reverse_merge_sort(int p, int r) {
        if( p < r ) {
            int q = (p + r) / 2;
            reverse_merge_sort(p, q);
            reverse_merge_sort(q + 1, r);
            reverse_merge(p, q ,r);
        }
    }

    void merge(int p, int q, int r) {
        ArrayType buffer;
        ArrayType a2[r - p + 1];
        int i = p, j = q + 1, k = 0;
        while( (i <= q) && (j <= r) ) {
            ArrayType s1 = a[i], s2 = a[j];
            if(a[i] < a[j]) {
                a2[k] = a[i];
                i++;
                k++;
            }
            else {
                a2[k] = a[j];
                j++;
                k++;
            }
        }
        while( i <= q  ) {
            a2[k] = a[i];
            i++;
            k++;
        }
        while( j <= r ) {
            a2[k] = a[j];
            j++;
            k++;
        }
        k = 0;
        for(int i = p; i <= r; i++) {
            a[i] = a2[k];
            k++;
        }
    }

    void merge_sort(int p, int r) {
        if( p < r ) {
            int q = (p + r) / 2;
            merge_sort(p, q);
            merge_sort(q + 1, r);
            merge(p, q ,r);
        }
    }

    ArrayType operator[](int index) {
        return a[index];
    }

    bool operator==(my_array<ArrayType> &b) {
        for(int i = 0; i < size; i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    ~my_array() {
        delete[](a);
    }

};


int main(int argc, char* argv[]) {

    for(int N = 1; N < 200000; N = N + 200) {
        int *random_array = my_array<int>::random_array(N);        
        my_array<int> a(N);
        a.init(random_array);
        a.reverse_merge_sort(0, N - 1);      
        long t1 = clock();
        a.insert_sort();
        long t2 = clock();
        cout << N << " " << t2 - t1 << " ";
        a.reverse_merge_sort();
        t1 = clock();
        a.merge_sort(0, N - 1);
        t2 = clock();
        cout << t2 - t1 << endl;
    }

    return 0;
}


// Unit test example
/*
TEST_CASE( "Sorts are computed", "[sorts]" ) {

    for(int i = 2; i < 10; i++ ) {
        int *random_array = my_array<int>::random_array(i);
        my_array<int> a(i);
        my_array<int> b(i);
        a.init(random_array);
        b.init(random_array);
        //a.show();
        //b.show();
        a.insert_sort();
        b.merge_sort(0, i - 1);
        //cout << (a == b) << endl;
        REQUIRE(a == b);
    }

}
*/
