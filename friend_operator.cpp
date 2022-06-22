#include<iostream>
using namespace std;

class complex; 
complex& __doapl (complex* ths, const complex& r);
 
class complex
{
    public:
        complex (double r=0, double i=0)
            : re(r), im(i)
        {}
        inline complex& operator += (const complex&);
        double real() const { return re; }
        double imag() const { return im; }

    private:
        double re,im;
        friend complex& __doapl (complex*, const complex&);
};

inline complex& __doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline complex& complex::operator += (const complex& r)
{
    return __doapl(this, r);
}
// 不能带上const，是会发生变化的
ostream& operator << (ostream& os, const complex& r)
{
    return os<< '(' << r.real() << ',' << r.imag() << ')';
}

int main(void)
{
    complex x(2, -3);
    complex y(4.5, 5.5);
    complex z(-2, 2.5);
    x += y += z; // 可以连续叠加！！！！！！！
    cout <<"x = "<< x.real() << "+" << x.imag() << "j" << endl;
    cout <<"y = "<< y.real() << "+" << y.imag() << "j" << endl;
    cout<<x<<"  "<<y;

    return 0;
}