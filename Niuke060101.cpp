#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
	//�ڲ���
	class Sum
	{
	public:
		Sum()
		{
			//�ڲ���ֱ�ӷ����ⲿ���˽�г�Ա
			_sum += _num;
			++_num;
			cout << "Sum" << endl;
		}
	};
	int Sum_Solution() {
		//����
		_sum = 0;
		_num = 1;
		Sum sumArray[5];  //����n��Sum��Ĺ��캯��������Sum��������
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