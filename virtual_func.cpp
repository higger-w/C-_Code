#include<iostream>

using namespace std;

class Root
{
public:
	Root(void){ 
		cout<<"Initializion of Root function"<<endl; 
	}
};

class Shy
{
public:
	Shy(void){ 
		cout<<"Initializion of Shy function. "<<endl; 
	}
};

class LGD: Root
{
public:
	LGD(void){ 
		cout<<"Initializion of LGD function."<<endl; 
	}
	Shy wbg();
};

int main(void)
{
	LGD n1ce;
	return 0;
}
