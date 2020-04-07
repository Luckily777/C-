141. 环形链表

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
    bool hasCycle(ListNode* head) {
        struct ListNode* fast, * slow;
        //设定快慢指针来进行查找
        if (head == NULL) {
            //首先判空
            return false;
        }
        fast = slow = head;
        //让快慢指针全部指向链表头地址
        while (fast && fast->next) {
            //快指针所指向的地址不为空
            fast = fast->next->next;
            //快指针向后走两步
            slow = slow->next;
            //慢指针向后走一步
            if (slow == fast) {
                //若相等则输出正确
                return true;
            }
        }
        return false;
    }
};