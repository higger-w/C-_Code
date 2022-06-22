#include<iostream>
using namespace std;

class Fraction
{
public:
    Fraction(int num, int den=1)
    :   mm(num), nn(den) {}
    // operator double() const {
    //     return (double)(mm/nn);
    // }
    Fraction operator+(const Fraction& f){
        return Fraction(this->mm * f.nn + this->nn * f.mm,this->nn * f.nn);
    }
private:
    int mm;
    int nn;
};
// ostream& operator << (ostream& os, const Fraction& r){
//   return os << r.mm << '/' << r.nn <<endl;
// }

int main(void){
    Fraction f1(3,5);
    Fraction f2(7,10);
    Fraction res = f2 + f1;
    

    return 0;
}