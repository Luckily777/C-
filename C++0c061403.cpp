//Բ���ŵ�����
//�º�����ģ��
template <class T>
struct Less
{
	//�������������
	bool operator()(const T& c1, const T& c2)
	{
		return c1 < c2;
	}
};

template <class T>
struct Greater
{
	//�������������
	bool operator()(const T& c1, const T& c2)
	{
		return c1 > c2;
	}
};


ostream& operator<<(ostream& cout, const C& c)
{
	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}


void test9()
{
	Less<C> lc;
	C c1(1, 2, 3);
	C c2(2, 2, 2);
	bool ret = lc.operator()(c1, c2);
	ret = lc(c1, c2);  // �ȼ��� lc.operator()(c1, c2)
}