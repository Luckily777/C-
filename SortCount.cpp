//��������


/*
ʱ�临�Ӷȣ�O(max(n,��Χ))
�ռ临�Ӷȣ�O(��Χ)
�ȶ���һ��̲���Ϊ���ȶ���(Ƿ��)
�������У�������
�������� ֻ�ʺ�С��Χ���ݣ� �����Χ�󣬿ռ临�ӶȽϸ�
*/

void SortCount(int* array, int n) {
	//ͳ�Ʒ�Χ
	int min = array[0], max = array[0];
	//�ҵ����ֵ����Сֵ
	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	//ȷ��׼ȷ�ķ�Χ
	int range = max - min + 1;
	//���Ÿ����ռ䣬���м���
	int* countArr = (int*)malloc(sizeof(int*)range);
	//������ĸ����ռ�ȫ����ʼ��Ϊ��
	memset(countArr, 0, sizeof(int) * range);
	//��ʼͳ�����ݳ��ֵĸ���
	for (int i = 0; i < n; i++) {
		//����һ�����һ��
		countArr[array[i] - min]++;
	}
	//�����м���
	int idx = 0;
	//�ָ����ݣ�������������
	for (int i = 0; i < range; i++) {
		while (countArr[i]--) {
			array[idx++] = i + min;
		}
	}
	//�ͷŸ����ռ�
	free(countArr);
}