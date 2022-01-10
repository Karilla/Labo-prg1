#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

template<typename T, typename U> void f(T,U){cout << "fonction 1" << endl;}

template<typename T, typename U> void f(T*,U){cout << "fonction 2" << endl;}

template<typename T> void f(T,T){cout << "fonction 3" << endl;}

template<typename T> void f(T,int){cout << "fonction 4" << endl;}

void f(int i, int y){cout << "fonction 5" << endl;}

void f(int* i, float j) {cout << "fonction 6" << endl;}

int main()
{
    char c = 'A'; 
    int i = 1, j = 2; 
    float x = 3.f, y = 4.f; 
    double z = 5.0; 

    //f(i, j); //fonction 5
    //f(c, i); //fonction 4
    //f(x, y); //fonction 3
    //f(i, z); //fonction 1
    //f(&i, j); //ambigu
    //f(&i, x); //fonction 6
    f(&i, z);  //fonction 2

}
