void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/*
ʱ�临�Ӷȣ�O(nlogn)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�  --> �����Ĺ��������λ�ÿ��ܻᷢ���仯
�������У�������
*/

void ShiftDown(int* array, int n, int parent) {
	int child = 2 * parent + 1;
	//Ѱ�Һ���λ��
	while (child < n) {
		if (child + 1 < n && array[child + 1] > array[child]) {
			//�ж�����������������£����Һ������ߵĽϴ�ֵ
			child++;
			//���ұߺ��ӱ���ߺ��Ӵ���childλ�ü�1
		}
		if (array[child] > array[parent]) {
			//�����ӱȸ��׵�ֵ���򽻻����׺ͺ��ӵ�λ��
			Swap(array, child, parent);
			parent = child;
			//���������½�����λ�ø��������
			child = 2 * parent + 1;
			//���¼����µĺ���λ��
		}
		else {
			break;
			//�������ֵС�ڸ��ף�������
		}
	}
}

void SortHeap(int* array, int n) {
	//���ѵĹ���
	for (int i = (n - 2) / 2; i >= 0; i--) {
		ShiftDown(array, n, i);
		//�������һ�����ڵ㿪ʼ���н���
	}
	//ѭ��ɾ��
	while (n) {
		Swap(array, 0, n - 1);
		n--;
		ShiftDown(array, n, 0);
	}
}