147. 对链表进行插入排序
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
			//从表头开始找第一个大于cur的节点
			start = newH;
			while (start->next && start->next->val <= cur->val)
				start = start->next;
			// start   cur    start->next
			prev->next = cur->next;
			cur->next = start->next;
			start->next = cur;
			//cur指向下一次需要排序的节点位置
			cur = prev->next;
		}
	}
	cur = newH->next;
	free(newH);
	return cur;

}