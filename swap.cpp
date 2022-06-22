#include <iostream>
using namespace std;
// void swapint(int *a,int *b)
// {
// 	int temp;
// 	temp=*a;
// 	*a=*b;
// 	*b=temp;
// } 
void swapint(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main ()
{
   // 声明简单的变量
   int	i=1,j=2;
   int &p=i;
   int &q=j;
   swapint(p,q);
   cout<<"i="<<i<<",j="<<j<<endl;

   return 0;
}
