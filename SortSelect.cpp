//��������
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


/*
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
�������У�������
*/

void selectSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		//start:δ�������ݵ������
		int start = i;
		//min: ��Сֵ��λ��
		int min = start;
		//��δ���������������Сֵ
		for (int j = start + 1; j < n; ++j)
		{
			if (array[j] < array[min]) {
				min = j;
				//��j��ֵ��minλ��
			}

		}
		Swap(array, start, min);
	}
}

