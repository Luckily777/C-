
������

void heapSort(int* array, int n)
{
	//����  O(n)
	for (int i = (n - 2) / 2; i >= 0; --i)
		//���ҵ����ڵ㣬�Դ�Ϊ���ҵ����нϴ���С��ֵ�����ڸ���
	{
		shiftDown(array, n, i);
	}
	//����: ѭ��βɾ �� nlogn
	int size = n;
	while (size > 1)
	{
		//ѭ��βɾ
		Swap(array, 0, size - 1);
		//������ĸ������һ��Ҷ�ӽ��н���
		--size;
		//size����
		shiftDown(array, size, 0);
		//�ٴν����µ�����
	}
}