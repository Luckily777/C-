//���û��volatile�Ļ���c++�������Ϊa�ǳ�����������ڴ洢���У����ָ�������a��ֵ֮��*pa���Ϊ20����aֻ��Ӵ洢����ȥȡ���������10��
//���������volatile�Ļ�����ֹ�Ż��������ڸ���֮ǰ��a����洢�����������ӡ������ֵ��a��*pa����20��

void test2()
{
	const volatile int a = 10;
	int* pa = (int*)&a;
	*pa = 20;
	cout << a << endl;
	cout << *pa << endl;
}

int main()
{
	//test1();
	////test2();
	//test3();
	//test4();
	test5();
	return 0;
}
