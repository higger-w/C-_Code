// std::bind主要有以下两个作用：
// 将可调用对象和其参数绑定成一个防函数
// 只绑定部分参数，减少可调用对象传入的参数

#include <iostream>
#include <functional>
using namespace std;

int add(int f, int s) {
    printf("first param :%d  second param:%d \n", f, s);
    return f + s;
}
double callableFunc (double x, double y) {
    return x/y;
}
class Base
{
public:
    void display_sum(int a1, int a2)
    {
        cout << a1 + a2 << '\n';
    }
 
    int m_data = 30;
};

int main ()
{
    //auto addFunc2 = bind(&add, 15, placeholders::_1);
    //等价于
    // function<int(int)> addFunc2 = bind(&add, 15, placeholders::_1);
    // cout << "addFunc2 >> " << addFunc2(5) <<endl;

    // auto NewCallable = bind (callableFunc, placeholders::_1,2);  
    // cout << NewCallable (10) << endl;
    
    /*
    bind绑定类成员函数时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址。
    必须显示的指定&Base::diplay_sum，因为编译器不会将对象的成员函数隐式转换成函数指针，所以必须在Base::display_sum前添加&；
    使用对象成员函数的指针时，必须要知道该指针属于哪个对象，因此第二个参数为对象的地址 &base； 
    */
    Base base;
    auto newiFunc = bind(&Base::display_sum, &base, 100, placeholders::_1);
    newiFunc(20); // should out put 120. 

    return 0;
}
