//vector����ʵ��

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
		//1 �������
		if (_finish == _eos)
		{
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}

		//2 ����
		*_finish = val;

		//3 ����size
		++_finish;
	}

	void reserve(size_t n)
	{
		//ֻ��������
		if (n > capacity())
		{
			size_t oldSize = size();
			//1. ���ռ�
			T* tmp = new T[n];

			//2. ����: �ڴ濽���� ǳ����
			//memcpy(tmp, _start, sizeof(T)* size());

			//2. ����� ����T���͵ĸ�ֵ�����
			for (int i = 0; i < size(); ++i)
			{
				tmp[i] = _start[i];
			}

			//3. �ͷ�ԭ�пռ�
			delete[] _start;

			//4. ���¿ռ�ָ�� ����
			_start = tmp;
			_finish = _start + oldSize;
			_eos = _start + n;
		}
	}

	//operator[]: �ɶ���д
	T& operator[](size_t pos)
	{
		if (pos < size())
			return _start[pos];
	}

	//operator[]: ֻ��
	const T& operator[](size_t pos) const
	{
		if (pos < size())
			return _start[pos];
	}

	//������
	//�ɶ���д
	typedef T* iterator;
	//ֻ��
	typedef const T* const_iterator;

	iterator begin()
	{
		//��һ��Ԫ�ص�λ��
		return _start;
	}

	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ�ã� Ҳ�������һ��Ԫ�صĽ���λ��
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

	//valĬ��ֵ�� �������ͣ�0ֵ�� �Զ������ͣ������޲ι���
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
		//����size
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		if (pos >= _start && pos <= _finish)
		{
			//�������
			if (_finish == _eos)
			{
				//���ݻᵼ�µ�����ʧЧ��������������ݣ����µ�����
				//���浱ǰλ������ʼλ�õ�ƫ����
				int len = pos - _start;

				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);

				//���µ�����
				pos = _start + len;
			}
			//�ƶ�Ԫ��
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			//����Ԫ��
			*pos = val;
			//����size
			++_finish;
		}
	}

	//���ص�������ִ�е�ǰ��ɾ��Ԫ�ص���һ��Ԫ��λ��
	iterator erase(iterator pos)
	{
		if (pos >= _start && pos < _finish)
		{
			//�ƶ�Ԫ��
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			//����size
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
		//����const�ӿڣ�ֻ��
		//v[i] = "a";
	}
	cout << endl;
	cout << "��������" << endl;
	Vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "��Χfor��" << endl;
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
		//д����
		v[i] = "a";
	}
	cout << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.operator[](i) << " ";
	}
	cout << endl;

	cout << "��������" << endl;
	//������
	Vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		*it = "b";
		++it;
	}
	cout << endl;

	cout << "��Χfor��" << endl;
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