#include <iostream>
using namespace std;
// 仿函数实现数组排序
class Compare
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 <= num2)
			return true;
		else
			return false;
	}
};

// void sort(int array[], int size, const Compare &cmp)
void sort(int* array, int size, const Compare &cmp)
{
	if (array == NULL)
		return;
	
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<=size-2-i; j++)
		{
			if (!(cmp(array[j], array[j+1])))
			{
				array[j] = array[j]^array[j+1];
				array[j+1] = array[j+1]^array[j];
				array[j] = array[j]^array[j+1];
			}
		}
	}
}

// void list(const int array[], int size)
void list(const int* array, int size)
{
	if (array == NULL)
		return;
	
	for(int i=0; i< size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	int array[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	sort(array, sizeof(array)/sizeof(int), Compare());
	list(array, sizeof(array)/sizeof(int));		
	return 0;
}