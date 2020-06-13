//vector功能实现

#include <string>
#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _eos - _start;
	}

	void pushBack(const T& val)
	{
		//1 检查容量
		if (_finish == _eos)
		{
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}

		//2 插入
		*_finish = val;

		//3 更新size
		++_finish;
	}

	void reserve(size_t n)
	{
		//只增加容量
		if (n > capacity())
		{
			size_t oldSize = size();
			//1. 开空间
			T* tmp = new T[n];

			//2. 拷贝: 内存拷贝， 浅拷贝
			//memcpy(tmp, _start, sizeof(T)* size());

			//2. 深拷贝： 调用T类型的赋值运算符
			for (int i = 0; i < size(); ++i)
			{
				tmp[i] = _start[i];
			}

			//3. 释放原有空间
			delete[] _start;

			//4. 更新空间指向， 容量
			_start = tmp;
			_finish = _start + oldSize;
			_eos = _start + n;
		}
	}

	//operator[]: 可读可写
	T& operator[](size_t pos)
	{
		if (pos < size())
			return _start[pos];
	}

	//operator[]: 只读
	const T& operator[](size_t pos) const
	{
		if (pos < size())
			return _start[pos];
	}

	//迭代器
	//可读可写
	typedef T* iterator;
	//只读
	typedef const T* const_iterator;

	iterator begin()
	{
		//第一个元素的位置
		return _start;
	}

	iterator end()
	{
		//最后一个元素的下一个位置， 也就是最后一个元素的结束位置
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	//val默认值： 内置类型：0值， 自定义类型：调用无参构造
	void resize(size_t n, const T& val = T())
	{
		if (n > capacity())
			reserve(n);
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish++ = val;

			}
		}
		//更新size
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		if (pos >= _start && pos <= _finish)
		{
			//检查容量
			if (_finish == _eos)
			{
				//增容会导致迭代器失效，如果发生了增容，更新迭代器
				//保存当前位置与起始位置的偏移量
				int len = pos - _start;

				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);

				//更新迭代器
				pos = _start + len;
			}
			//移动元素
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			//插入元素
			*pos = val;
			//更新size
			++_finish;
		}
	}

	//返回迭代器：执行当前被删除元素的下一个元素位置
	iterator erase(iterator pos)
	{
		if (pos >= _start && pos < _finish)
		{
			//移动元素
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			//更新size
			--_finish;
		}
		return pos;
	}

private:
	T* _start;
	T* _finish;
	T* _eos;  //end of storage
};

template <class T>
void printVector(const Vector<T>& v)
{
	cout << "operator[]:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		//调用const接口，只读
		//v[i] = "a";
	}
	cout << endl;
	cout << "迭代器：" << endl;
	Vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "范围for：" << endl;
	for (const T& str : v)
	{
		cout << str << " ";
	}
	cout << endl;

}

void test()
{
	Vector<int> v;
	Vector<char> v2;
	Vector<string> v3;

	size_t size = v.size();
	size = v2.size();
	size = v3.size();

	size_t cap = v.capacity();
	cap = v2.capacity();
	cap = v3.capacity();
}

void test2()
{
	Vector<int> v;
	v.pushBack(1);
	size_t size = v.size();
	size_t cap = v.capacity();

	v.pushBack(2);
	size = v.size();
	cap = v.capacity();
	v.pushBack(3);
	size = v.size();
	cap = v.capacity();
	v.pushBack(4);
	size = v.size();
	cap = v.capacity();
	v.pushBack(5);
	size = v.size();
	cap = v.capacity();
	v.pushBack(6);
	size = v.size();
	cap = v.capacity();
}


void test3()
{
	Vector<string> v;
	v.pushBack("1");
	v.pushBack("2");
	v.pushBack("3");
	v.pushBack("4");
}

void test4()
{
	Vector<string> v;
	v.pushBack("1");
	v.pushBack("2");
	v.pushBack("3");
	v.pushBack("4");

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		//写操作
		v[i] = "a";
	}
	cout << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.operator[](i) << " ";
	}
	cout << endl;

	cout << "迭代器：" << endl;
	//迭代器
	Vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		*it = "b";
		++it;
	}
	cout << endl;

	cout << "范围for：" << endl;
	for (string& str : v)
	{
		cout << str << " ";
		str = "c";
	}
	cout << endl;

	cout << "printVector:" << endl;
	printVector(v);
}

void test5()
{
	Vector<int> v;
	Vector<char> v2;
	Vector<string> v3;

	v.resize(5);

	v2.resize(5);

	v3.resize(5);
}

void test6()
{
	Vector<int> v;
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.end(), 4);
	v.insert(v.end(), 5);
	v.insert(v.end(), 6);
	v.insert(v.end(), 7);
	printVector(v);

	v.erase(v.end() - 1);
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
}

void test7()
{
	Vector<int> v;
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.end(), 4);
	v.insert(v.end(), 5);
	v.insert(v.end(), 6);
	v.insert(v.end(), 7);

	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 1)
			it = v.erase(it);
		else
			++it;
	}

	printVector(v);
}



int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}