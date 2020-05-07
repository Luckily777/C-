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


//�ڶ���ѡ�����򣬴����߿�ʼ����ѡ������
void selectSort2(int* array, int n) {
	int begin = 0;
	//����ߵ�λ��
	int end = n - 1;
	//���ұߵ�λ��
	while (begin < end) {
		//���С���ұ�
		int min = begin, max = begin;
		//��ʼ��min��maxλ��ȫ��ָ���ʼ
		for (int i = begin + 1; i < end; i++) {
			if (array[i] >= array[max]) {
				//�ҵ�����λ��
				max = i;
			}
			if (array[i] <array[min]) {
				//�ҵ���С��λ��
				min = i;
			}
		}
		Swap(array, begin, min);
		//����С��λ�ú�����ߵ����ݽ���
		if (max == begin) {
			//�����ĵ�����ߵ�����ʱ�����ʾ���ݷ����˱仯
			max = min;
			//��minλ�ø�ֵ��max
		}
		Swap(array, end, max);
		//�������ֵ�Ľ���
		begin++;
		end--;
	}
}
