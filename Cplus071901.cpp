//λͼ
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		_bit.resize(range / 32 + 1);
	}

	//��ѯ��Test
	bool Test(size_t n)
	{
		//����λ��
		int idx = n / 32;
		int bitIdx = n % 32;
		//��ȡ��Ӧbitλ������ֵ
		if ((_bit[idx] >> bitIdx) & 1)
			return true;
		else
			return false;
	}
	//�洢: Set
	void Set(size_t n)
	{
		int idx = n / 32;
		int bitIdx = n % 32;

		_bit[idx] |= (1 << bitIdx);

	}

	//ɾ��: Reset
	void Reset(size_t n)
	{
		int idx = n / 32;
		int bitIdx = n % 32;

		_bit[idx] &= ~(1 << bitIdx);
	}
private:
	vector<int> _bit;
};

void testBit()
{
	BitMap bit(100);

	bit.Set(4);
	bit.Set(31);
	bit.Set(48);

	bool ret = bit.Test(4);
	ret = bit.Test(31);
	ret = bit.Test(48);
	ret = bit.Test(25);

	bit.Reset(31);
	bit.Reset(4);
	bit.Reset(48);
}