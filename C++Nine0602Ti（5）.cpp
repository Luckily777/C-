//字符串相加
#include <string>

string addString(string num1, string num2) {
	int begin1 = num1.size() - 1;
	int begin2 = num2.size() - 1;

	//进位
	int step = 0;
	string sum;

	//也可以提前开好空间
	sum.reserve(begin1 > begin2 ? begin1+1 : begin2+1);

	//从低位开始相加
	while (begin1 >= 0 || begin2 >= 0) {
		//cursum：当亲位的和，可以先制为上一步的进位
		int curSum = step;
		if (begin1 >= 0)
			curSum += num1[begin1--] - '0';
		if (begin2 >= 0)
			curSum += num2[begin2--] - '0';

		//是否需要进位
		if (curSum > 9) {
			step = 1;
			curSum -= 10;
		}
		else {
			step = 0;
			//保存当前的和
		}
		//1. 尾插效率较低
		sum.insert(0, 1, curSum + '0');
		//2. 倒序存放
		sum += curSum + '0';
	}
	//最后一步，是否有进位
	if (step == 1)
		sum.insert(0, 1, '1');
	//倒叙 reverse(sum.begin(), sum.end());
	return sum;
}