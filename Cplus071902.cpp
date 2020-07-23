//布隆过滤器
#include <string>
#include <vector>
#include <iostream>
using namespace std;


template <class T, class HF1, class HF2, class HF3>
class BloomFilter
{
public:
	// bit位数量 = 哈希函数个数 * 数据量 / ln2
	BloomFilter(size_t num)
		:_bit(5 * num)
		, _bitCount(5 * num)
	{}

	// Set
	void Set(const T& value)
	{
		HF1 hf1;
		HF2 hf2;
		HF3 hf3;
		//计算哈希值
		size_t hashCode1 = hf1(value);
		size_t hashCode2 = hf2(value);
		size_t hashCode3 = hf3(value);

		_bit.Set(hashCode1 % _bitCount);
		_bit.Set(hashCode2 % _bitCount);
		_bit.Set(hashCode3 % _bitCount);
	}

	// Test
	bool Test(const T& value)
	{
		HF1 hf1;
		size_t hashCode1 = hf1(value);
		if (!_bit.Test(hashCode1 % _bitCount))
			return false;
		HF2 hf2;
		size_t hashCode2 = hf2(value);
		if (!_bit.Test(hashCode2 % _bitCount))
			return false;
		HF3 hf3;
		size_t hashCode3 = hf3(value);
		if (!_bit.Test(hashCode3 % _bitCount))
			return false;

		//返回true: 不一定正确
		return true;
	}

private:
	BitMap _bit;
	size_t _bitCount;

};

struct strToInt1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct strToInt2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

struct strToInt3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (auto& ch : str)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};

void testB()
{
	BloomFilter<string, strToInt1, strToInt2, strToInt3> bf(300);
	string str1 = "http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_set";
	string str2 = "http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_se";
	string str3 = "http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_ses";

	string str4 = "http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_se1";
	string str5 = "http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_seq";

	bf.Set(str1);
	bf.Set(str2);
	bf.Set(str3);

	bool ret = bf.Test(str1);
	ret = bf.Test(str2);
	ret = bf.Test(str3);
	ret = bf.Test(str4);
	ret = bf.Test(str5);

}