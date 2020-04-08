
ɾ���������ظ��Ľ��
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		struct ListNode* prev, * cur, * next, * tmp;
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		prev = NULL;
		cur = pHead;
		next = cur->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				//�ҵ���һ�����ظ��Ľڵ�
				while (next && next->val == cur->val)
					next = next->next;
				//�ͷ��ظ�������
				while (cur != next)
				{
					tmp = cur->next;
					free(cur);
					cur = tmp;
				}
				//��������
				if (prev == NULL)
				{
					//ɾ����Ϊͷ���, ����ͷ���
					pHead = cur;
				}
				else
					prev->next = cur;
				if (next)
					next = next->next;
			}
		}
		return pHead;
	}
};