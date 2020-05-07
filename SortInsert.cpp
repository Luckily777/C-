//��������
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
	ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
	�������У�����
*/

void insertSort(int* array, int n) {
	//���б���
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		//�������е����һ��λ��
		int key = array[end + 1];
		//�������һ������
		while (end >= 0 && array[end] > key) {
			//�ҵ���һ��С�ڵ���key��λ��
			array[end + 1] = array[end];
			//����ǰ��������ƶ�
			--end;
		}
		array[end + 1] = key;
		//��key���ݴ���ڵ�ǰλ��
	}
}