#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
	//内部类
	class Sum
	{
	public:
		Sum()
		{
			//内部类直接访问外部类的私有成员
			_sum += _num;
			++_num;
			cout << "Sum" << endl;
		}
	};
	int Sum_Solution() {
		//重置
		_sum = 0;
		_num = 1;
		Sum sumArray[5];  //调用n次Sum类的构造函数，创建Sum对象数组
		return _sum;
	}
//private:
	static int _sum;
	static int _num;
};

int Solution::_sum = 0;
int Solution::_num = 1;

void test5()
{
	Solution s;
	int sum = s.Sum_Solution();
	cout << Solution::_num << endl;
	cout << sum << endl;
}

int main() {
	test5();
	return 0;
}