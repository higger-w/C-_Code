#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
// not1是构造一个与谓词结果相反的一元函数对象。
// not2是构造一个与谓词结果相反的二元函数对象。
int main()
{
	vector<int> nums = { 5, 3, 4, 9, 1, 7, 6, 2, 8 };
	//升序
	function<bool(int, int)> ascendingOrder = [](int a, int b) { return a < b; };
	// 排序，不是按升序，而是按降序
	sort(nums.begin(), nums.end(), not2(ascendingOrder));
	for (int i : nums) {
		cout << i << " ";
	}
	return 0 ;
}
