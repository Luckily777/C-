//��������
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
ʱ�临�Ӷȣ��O(n^1.3) ƽ��O(n^1.3)  ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�  ---> ����ʱ��ֵͬ��Ԫ�ز�һ�����Էֵ�ͬһ�飬Ԥ�����ǿ��ܵ������λ�÷����仯
�������У�����
*/

void shellSort(int* array, int n) {
	int gap = n;
	//����
	while (gap > 1) {
		gap = gap / 3 + 1;
		//�������� ͨ����ͬ��gap�������߼�����
		//�����ڽ��в������� ��ͬ���Ԫ�ؽ����������

		for (int i = 0; i < n - gap; i++) {
			//һ�ֲ�������
			int end = i;
			//��������һ��λ��
			int key = array[end + gap];
			//ͬ����֮�е�һ��Ҫ���������
			while (end >= 0 && array[end] > key) {
				//�ҵ���һ��С�ڵ��ڵ�����
				array[end + gap] = array[end];
				//���������˲��
				end -= gap;
				//end���¸�ֵ
			}
			array[end + gap] = key;
			//������Ҫ��������ݲ��뵽�µ�λ��
		}
	}
}