void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}



//Hore�ָ
int PartionHora(int* array, int begin, int end) {
	//ѡ���׼ֵ
	int key = array[begin];
	int start = begin;
	//��ʼ����
	while (begin < end) {
		//�Ӻ���ǰ���ҵ�һ��С��key��ֵ
		while (begin < end && array[end] >= key) {
			end--;
		}
		//��ǰ����ҵ�һ������key��ֵ
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//�����ҵ�������ֵ��λ��
		Swap(array, begin, end);
	}
	//��󽫻�׼ֵ������λ�õ�ֵ���н���
	Swap(array, start, begin);
	//���ػ�׼ֵ�������λ��
	return begin;
}

//�ڿӷָ
int PartionHole(int* array, int begin, int end) {
	//��׼ֵȡ�������ճ������
	int key = array[begin];
	//��ʼ����
	while (begin < end) {
		//�Ӻ��ҵ�һ��С��key��λ��
		while (begin < end && array[end] >= key) {
			end--;
		}
		//���ҵ��Ĵ�λ��ֵ���׼ֵ�Ŀ���ճ�һ���µĿ�
		array[begin] = array[end];
		//��ǰ����ҵ���һ������key��λ��
		while (begin < end && array[begin] >= key) {
			begin++;
		}
		//���ҵ���λ�õ�ֵȡ�����֮ǰ�Ŀ�֮�У��ֿճ���һ���¿�
		array[end] = array[begin];
	}
	//ֱ������֮�󣬽�����Ļ�׼ֵ�������ճ����Ŀ�֮��
	array[begin] = key;
	//���ػ�׼ֵ��ʱ��λ��
	return begin;
}

//ǰ��ָ��ָ
int PartionHand(int* array, int begin, int end) {
	//���һ��С�ڻ�׼ֵ��λ��
	int last = begin;
	//�·��ֵ���һ��С�ڻ�׼ֵ��λ��
	int next = last + 1;
	//��׼ֵ
	int key = array[begin];
	//��ʼ����
	while (next <= end) {
		//��next��ָ������С�ڻ�׼ֵ����last��next֮�仹������������
		//���������֮�仹�����Ŵ��ڻ�׼ֵ�����ݴ��ڣ����н���
		//�����������ƶ���С��������ǰ�ƶ�
		if (array[next] < key && ++last != next) {
			Swap(array, last, next);
			next++;
		}
	}
	//���next����֮�󣬽�last��λ�ú��ʼ�Ļ�׼ֵλ�ý��н���
	Swap(array, begin, last);
	return last;
	//���ػ�׼ֵ��λ��
}


void QuichSort(int* array, int begin, int end) {
	if (begin >= end) {
		//��begin��end֮��û������Ԫ�أ����ʾ�����������
		return;
	}
	int keyPos = PartionHora(array, begin, end);
	//�Դ˻�׼ֵ�������ֵ�ǰ����

	QuichSort(array, begin, keyPos - 1);
	//�ݹ鷨�������������
	QuichSort(array, keyPos + 1, end);
	//�ݹ鷨�����ұ�������

}