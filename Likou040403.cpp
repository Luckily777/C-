������ 02.02.���ص����� k ���ڵ�

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* fast, * blow;
        fast = head;
        blow = head;
        while (k--) {
            ListNode* next = fast->next;
            fast = next;
        }
        while (fast) {
            fast = fast->next;
            blow = blow->next;
        }
        return blow->val;
    }
};