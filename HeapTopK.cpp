//TopK���⣺ �ҳ�N�����������/��С��ǰK�����⡣
//����ʵ�������汾��


//1. ������K��Ԫ��
//�����ΪС��
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//��������K��Ԫ�صĶ�
	HeapInit(&hp, a, k);

	for (size_t i = k; i < n; ++i)  // N
	{
		//ÿ�κͶѶ�Ԫ�رȽϣ����ڶѶ�Ԫ�أ���ɾ���Ѷ�Ԫ�أ������µ�Ԫ��
		if (a[i] > HeapTop(&hp)) // LogK
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

//2. ����С��K��Ԫ��
//�����Ϊ���
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//��������K��Ԫ�صĶ�
	HeapInit(&hp, a, k);

	for (size_t i = k; i < n; ++i)  // N
	{
		//ÿ�κͶѶ�Ԫ�رȽϣ�С�ڶѶ�Ԫ�أ���ɾ���Ѷ�Ԫ�أ������µ�Ԫ��
		if (a[i] < HeapTop(&hp)) // LogK
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//�������10000�����������飬��֤Ԫ�ض�С��1000000
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//ȷ��10��������
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	PrintTopK(int* a, n, 10);
}
