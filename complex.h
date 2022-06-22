#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__
// 类声明 方法声明
class complex; 
complex&
  __doapl (complex* ths, const complex& r);
complex&
  __doami (complex* ths, const complex& r);
complex&
  __doaml (complex* ths, const complex& r);


class complex
{
public:
  complex (double r = 0, double i = 0) // 构造函数
    : re (r), im (i)                   // 初值列
  { }
  // 成员函数，可以用 this 隐式访问调用对象的成员
  // 所有参数（操作数）必须都是 complex类型
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  double real () const { return re; }
  double imag () const { return im; }
private:
  double re, im;
  // 友元函数，使其能取re、im的值
  friend complex& __doapl (complex *, const complex&);
  friend complex& __doami (complex *, const complex&);
  friend complex& __doaml (complex *, const complex&);
};


inline complex& __doapl (complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}
 
inline complex& complex::operator += (const complex& r)
{
  return __doapl (this, r);
}

inline complex& __doami (complex* ths, const complex& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;
}
 
inline complex& complex::operator -= (const complex& r)
{
  return __doami (this, r);
}
 
inline complex& __doaml (complex* ths, const complex& r)
{
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}

inline complex& complex::operator *= (const complex& r){
  return __doaml (this, r);
}

// 不能带上const，是会发生变化的
std::ostream& operator << (std::ostream& os, const complex& r){
  return os << '(' << r.real() << ',' << r.imag() << ')';
}

// 全局函数（非成员函数），为了方便用户使用
// 使用方法是 imag(x) \ real(x)
inline double imag (const complex& x){
  return x.imag ();
}
inline double real (const complex& x){
  return x.real ();
}

// 函数重载，双操作数
inline complex operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
}

inline complex operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
}

inline complex operator + (double x, const complex& y)
{
  return complex (x + real (y), imag (y));
}

inline complex operator - (const complex& x, const complex& y)
{
  return complex (real (x) - real (y), imag (x) - imag (y));
}

inline complex operator - (const complex& x, double y)
{
  return complex (real (x) - y, imag (x));
}

inline complex operator - (double x, const complex& y)
{
  return complex (x - real (y), - imag (y));
}

inline complex operator * (const complex& x, const complex& y)
{
  return complex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

inline complex operator * (const complex& x, double y)
{
  return complex (real (x) * y, imag (x) * y);
}

inline complex operator * (double x, const complex& y)
{
  return complex (x * real (y), x * imag (y));
}

complex operator / (const complex& x, double y)
{
  return complex (real (x) / y, imag (x) / y);
}
// 单个参数，操作变量在操作符之后
inline complex operator + (const complex& x)
{
  return x;
}
inline complex operator - (const complex& x)
{
  return complex (-real (x), -imag (x));
}

inline bool operator == (const complex& x, const complex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool operator == (const complex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}

inline bool operator == (double x, const complex& y)
{
  return x == real (y) && imag (y) == 0;
}

inline bool operator != (const complex& x, const complex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool operator != (const complex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}

inline bool operator != (double x, const complex& y)
{
  return x != real (y) || imag (y) != 0;
}

#include <cmath>

inline complex
polar (double r, double t)
{
  return complex (r * cos (t), r * sin (t));
}

inline complex
conj (const complex& x) 
{
  return complex (real (x), -imag (x));
}

inline double
norm (const complex& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

#endif   //__MYCOMPLEX__