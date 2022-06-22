#include <iostream>
#include "complex.h"
using namespace std;

int main(){
    complex x(2, -3);
    complex y(4.5, 5.5);
    complex z(-2, 2.5);
    x += y += z;

    cout<<x<<y;
    return 0;
}