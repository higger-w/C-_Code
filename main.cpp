#include <iostream>
using namespace std;
class A{
public:
    A(int v1, int v2, int v3)
    : a(v1),b(v2),c(v3)
    {}
    ~A()=default;
    int a=1;
protected:
    int b=2;
private:
    int c=3;
};
class B: private A{
public:
    B(int R, int N, int G): A(R,N,G)
    {
        this->x=R*R;
        this->y=N*N;
        this->z=G*G;
    }
    ~B()=default;
    int x=4;
    void const ptf(void){
        cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
        // cout<<"a = "<<a<<", b = "<<b<<endl;
    }
protected:
    int y=5;
private:
    int z=6;
};

int main(){
    B cat(3,4,5);
    cat.ptf();

    return 0;
}