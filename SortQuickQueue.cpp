//ʹ�ö���ʵ�ַǵݹ�Ŀ�������


void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


void SortQuickQueue(int* array, int n) {
	//��������
	Queue q;
	//���г�ʼ��
	QueueInit(&q);

	if (n > 1) {
		//��Ӳ���
		QueuePush(&q, 0);
		QueuePush(&q, n - 1);
	}
	while (QueueEmpty(&q) != 1) {
		//��ȡ��ͷԪ��
		int begin = QueueFront(&q);
		//ɾ����ͷԪ��
		QueuePop(&q);
		//��ȡ��ͷԪ��
		int end = QueueFront(&q);
		//ɾ����ͷԪ��
		QueuePop(&q);

		//�ҵ���׼ֵλ��
		int keyPos = PartionThree(array, begin, end);
		if (begin < keyPos - 1) {
			//��벿��
			QueuePush(&q, begin);
			QueuePush(&q, keyPos-1);
		}
		if (keyPos + 1 < end) {
			//�Ұ벿��
			QueuePush(&q, keyPos+1);
			QueuePush(&q, end);
		}
	}
}