
删除链表中重复的结点
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
				//找到第一个不重复的节点
				while (next && next->val == cur->val)
					next = next->next;
				//释放重复的区间
				while (cur != next)
				{
					tmp = cur->next;
					free(cur);
					cur = tmp;
				}
				//重新连接
				if (prev == NULL)
				{
					//删除的为头结点, 更新头结点
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