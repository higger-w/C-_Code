#include <iostream>     // std::cout
#include <functional>   // std::plus
#include <algorithm>    // std::transform
using namespace std;
int main(void)
{
    cout << minus<int>()(10,5) << endl;//5
    cout << multiplies<int>()(10,5) << endl;//50
    cout << divides<int>()(10,5) << endl;//2
    cout << modulus<int>()(10,5) << endl;//0
    cout << negate<int>()(10) << endl;//-10
    return 0;
}