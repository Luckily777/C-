Å£¿Í¿¼ÊÔÌâ

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* fast, * slow;
        fast = slow = pListHead;
        while (k--)
        {
            if (fast)
                fast = fast->next;
            else
                return NULL;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};