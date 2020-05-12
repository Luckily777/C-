//�Ż��µÿ������� ��������ȡ��

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


//����ȡ�з���
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	//ѡ��begin����end���м�λ��
	if (array[begin] < array[mid]) {
		//����ʼλ�õ�ֵС���м�λ��
		if (array[mid] < array[end]) {
			//���м�λ�õ�ֵС��β��λ�õ�ֵ
			return mid;
			//�򷵻��м��ֵ
		}
		else {
			if (array[begin] > array[end]) {
				//��������ʼλ�õ�ֵҲ����β��λ�õ�ֵ
				return begin;
				//�򷵻ؿ�ʼλ��
			}
			else {
				return end;
				//���򷵻�β��λ��
			}
		}
	}
	else {
		//���м�λ�õ�ֵ��������ʼλ�õ�ֵ
		if (array[begin] < array[end]) {
			//��ʼλ��С��β��λ�õ�ֵ
			return mid;
			//�򷵻��м�λ��
		}
		else {
			if (array[begin] < array[end]) {
				//���м�λ�ò�������ʼλ�ã��ҿ�ʼλ�ò�С��β��λ�õ�ֵ
				return begin;
				//�򷵻ؿ�ʼλ��
			}
			else {
				return end;
				//���򷵻�β��λ��
			}
		}
	}
}


//hora��
int PartionOne(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//����ȡ�� �ҵ�midֵ
	Swap(array, begin, mid);
	//���н���

	//ȷ����׼ֵ
	int key = array[begin];
	//��ʼλ��
	int start = begin;


	while (begin < end) {
		//�Ӻ���ǰ���ҵ�һ��С�ڻ�׼ֵ��λ��
		while (begin < end && array[end] >= key) {
			end--;
		}
		//��ǰ����ҵ�һ�����ڻ�׼ֵ��λ��
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//���߽��н���
		Swap(array, begin, end);
	}
	//���������λ�úͳ�ʼλ�ý��н���
	Swap(array, start, begin);

	//���ػ�׼ֵλ��
	return begin;
}


//�ڿӷ�
int PartionTwo(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//����ȡ�� �ҵ�midֵ
	Swap(array, begin, mid);
	//���н���

	//ȷ����׼ֵ
	int key = array[begin];
	while (begin < end) {
		//�Ӻ���ǰ�ҵ�һ��С�ڻ�׼ֵ��λ��
		while (begin < end && array[end] >= key) {
			end--;
		}
		//����λ�õ�ֵ������һ��ʼ�Ļ�׼ֵ��֮��
		array[begin] = array[end];
		//��ǰ����ҵ�һ�����ڻ�׼ֵ��λ��
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//����λ�õ�ֵ����֮ǰ�ҵ���С�ڻ�׼ֵ��λ��
		array[end] = array[begin];
	}
	//���key��ֵ����������λ��
	array[begin] = key;
	//���ػ�׼ֵλ��
	return begin;
}


//ǰ��ָ�뷨
int PartionThree(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//����ȡ�� �ҵ�midֵ
	Swap(array, begin, mid);
	//���н���

	//���һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;
	//��׼ֵ
	int key = array[begin];
	while (cur <= end) {
		//����һ����׼ֵλ�ú����һ����׼ֵλ��֮�䲻����
		if (array[cur] < key && ++prev != cur) {
			//����н���
			Swap(array, prev, cur);
		}
		cur++;
	}
	//��������׼ֵ�ͻ�׼ֵ��λ��
	Swap(array, begin, prev);
	return prev;
}


/*
ʱ�临�Ӷȣ����O(n^2)-->�������   ���:O(nlogn)  ƽ����O(nlogn)
�ռ临�Ӷȣ�O(logn)  ��������ջ��  �������: O(n)-->�������
�ȶ��ԣ����ȶ�
�������У�����
*/

void SortQucik(int* array, int begin, int end) {
	if (begin >= end) {
		//��hֻʣ�����һ��Ԫ��ʱ����ֱ�ӷ���
		return;
	}
	int keyPos = PartionOne(array, begin, end);
	//Ѱ�ҵ�һ����׼ֵ
	SortQucik(array, begin, keyPos);
	//��߷�
	SortQucik(array, keyPos+1,end);
	//�ұ߷�
}