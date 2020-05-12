//�ǵݹ�Ĺ鲢����

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

void SortMergeNoR(int* array, int n) {
	//�����µĿռ�
	int* tmp = (int*)malloc(sizeof(int) * n);
	//���ÿ��
	int k = 1;

	//��ʼ���ֵĺϲ�
	while (k < n) {
		//һ�ֺϲ�
		for (int i = 0; i < n; i += 2 * k) {
			int begin = i;
			int mid = i + k - 1;

			//���м�ֵ�������λ�����������
			if (mid >= n - 1) {
				continue;
			}
			int end = i + 2 * k - 1;
			
			//��ĩβֵ�������λ��ʱ����ĩβֵ�õ����һ��λ��
			if (end >= n) {
				end = n - 1;
			}
			//�ϲ�
			Merge(array, begin, mid, end, tmp);
		}
		//�������2��
		k *= 2;
	}
}