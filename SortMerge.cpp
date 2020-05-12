//�鲢����


//�ϲ����� ǰ������Ҫ֪���������������е����� [begin ,mid ][mid+1 end]
void Merge(int* array, int begin, int mid, int end, int* tmp) {
	int begin1 = begin, end1 = end, begin2 = mid + 1, end2 = end;
	int idx = begin;

	//�����������н�������
	while (begin1 <= end1 && begin2 <= end2) {
		if (array[begin1] <= array[begin2]) {
			//����������֮�н�С��ֵ���뵽tmp֮��
			tmp[idx++] = array[begin1++];
		}
		else {
			tmp[idx++] = array[begin2++];
		}
	}
	//��ʣ�������ֱ�ӿ�������ǰ�Ŀռ�֮��
	if (begin1 < end1) {
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	if (begin2 < end2) {
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));
	}
	//֮��tem֮�е����ݿ�����ԭʼ�ռ�֮��
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void SortMergeR(int* array, int begin, int end, int* tmp) {
	if (begin >= end) {
		//��Begin��end֮��û���κ����ݣ���ֱ�ӷ���
		return;
	}
	//�����м�λ��
	int mid = begin + (end - begin) / 2;

	//�Ƚ��������������
	SortMergeR(array, begin, mid, tmp);
	SortMergeR(array, mid + 1, end, tmp);

	//���ϲ������������
	Merge(array, begin, mid, end, tmp);
}

/*
ʱ�临�Ӷȣ�O(nlogn)
�ռ临�Ӷȣ�O(n)
�ȶ����ȶ�
�������У�������
*/
void SortMerge(int* array, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	SortMergeR(array, 0, n - 1, tmp);
	free(tmp);
}