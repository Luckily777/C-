void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/*
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
�������У�����
*/

void bubbleSort(int* array, int n) {
	while (n) {
		//ѭ��n�� 
		int flag = 1;
		//���ñ�ʶ��������ʶ���ı䣬����ζ�Ŵ������Ѿ�����������
		int end = n;
		//����λ��
		for (int i = 1; i < end; i++) {
			if (array[i - 1] > array[i]) {
				//��ǰһ����ں�һ�����н���
				Swap(array, i, i - 1);
				//֮�󽫱�ʶ������
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
		n--;
	}
}