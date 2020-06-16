//vector ���ܽӿ�ʵ��

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

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}

	Vector(const Vector<T>& v)
		: _start(new T[v.capacity()])
	{
		//���
		for (int i = 0; i < v.size(); ++i)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.size();
		_eos = _start + v.capacity();
	}

	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_eos, v._eos);
	}

private:
	T* _start;
	T* _finish;
	T* _eos;  //end of storage
};

template <class T>
void printVector(const Vector<T>& v)
{
	//cout << "operator[]:" << endl;
	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//	//����const�ӿڣ�ֻ��
	//	//v[i] = "a";
	//}
	//cout << endl;
	//cout << "��������" << endl;
	//Vector<T>::const_iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

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
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	v.pushBack(6);
	v.pushBack(7);

	cout << sizeof(v) << endl;

	Vector<int> copy(v);
	Vector<int> copy2(v);

	printVector(v);
	printVector(copy);
	printVector(copy2);

	v = copy;
}


//int main()
//{
//	test();
//	return 0;
//}