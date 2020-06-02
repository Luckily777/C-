//���ͱ��

//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//���ͱ�̲�û�м���ʵ�ʵĴ�������ֻ�ǰ��ظ��Ĵ��뽻�������Զ����ɣ�
//���ٿ�����Ա���ظ��Ĺ���������߹���Ч�ʣ������Ҹ���
/*
template < typename / class ���Ͳ���1�� typename / class���Ͳ���2��.....>
��������
*/
//����ģ��
//����ģ��ʵ��������ʵ�ʲ������ͣ����ɿ�ִ�еĺ���
template <class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template <class T>
T add(T a, T b)
{
	return a + b;
}

void test9()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	//��ʽʵ���������������Ӳ��������Զ��Ƶ�������ֱ�ӿ�ִ�еĴ���
	Swap(a, b);
	Swap(c, d);

	Date d1(2020);
	Date d2(2030);
	Swap(d1, d2);

	//Swap<int>(a, c);
	add(a, b);

	add<int>(a, c);
	add<char>(a, c);
	add(a, (int)c);
	//��ʽʵ������ ������ + <����> +(�����б�
	Swap<int>(a, b);
}
