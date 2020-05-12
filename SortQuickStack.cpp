//ʹ��ջʵ�ַǵݹ�Ŀ�������


void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


void SortQuickStack(int* array, int n) {
	//����ջ
	Stack st;
	//��ʼ��ջ
	StackInit(&st, 10);

	//��ջ����
	if (n > 1) {
		//�������
		StackPush(&st, n - 1);
		//���뿪ʼ
		StackPush(&st, 0);
	}
	
	while (StackEmpty(&st) != 1) {
		//��ȡջ��Ԫ�أ����Ǻ����
		int begin = StackTop(&st);
		//ɾ��ջ��Ԫ��
		StackPop(&st);
		//�ٴλ�ȡջ��Ԫ��
		int end = StackTop(&st);
		//ɾ��ջ��Ԫ��
		StackPop(&st);

		//���صĻ�׼ֵλ��
		int keyPos = PartionThree(array, begin, end);

		if (keyPos + 1 < end) {
			//��벿����������δ����Ԫ��
			//��ջ
			StackPush(&st, end);
			StackPush(&st, keyPos+1);
		}
		if (begin < keyPos - 1) {
			//ǰ�벿������������δ����Ԫ��
			//��ջ
			StackPush(&st, keyPos - 1);
			StackPush(&st, begin);
		}
	}
}