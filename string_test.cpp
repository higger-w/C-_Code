#include "mystr.h"
#include <iostream>

using namespace std;

int main()
{
    String s1("Hello ");
    String s2("World ");
    
    String s3(s2);
    cout << s3 <<endl;

    s3 = s1;
    cout << s3 << s2 << s1 <<endl;
} 