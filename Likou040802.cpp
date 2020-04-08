147. ��������в�������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* insertionSortList(struct ListNode* head) {
	struct ListNode* cur, * prev, * start, * newH;
	if (head == NULL || head->next == NULL)
		return head;
	prev = head;
	cur = head->next;
	newH = (struct ListNode*) malloc(sizeof(struct ListNode));
	newH->next = head;
	while (cur)
	{
		if (cur->val >= prev->val)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			//�ӱ�ͷ��ʼ�ҵ�һ������cur�Ľڵ�
			start = newH;
			while (start->next && start->next->val <= cur->val)
				start = start->next;
			// start   cur    start->next
			prev->next = cur->next;
			cur->next = start->next;
			start->next = cur;
			//curָ����һ����Ҫ����Ľڵ�λ��
			cur = prev->next;
		}
	}
	cur = newH->next;
	free(newH);
	return cur;

}