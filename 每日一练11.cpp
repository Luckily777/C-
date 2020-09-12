//合并有序链表

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if (l1 == nullptr) {
            return l2;
        }//若l1为空，则直接返回l2
        if (l2 == nullptr) {
            return l1;
        }//若l2为空，则直接返回l1
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (l1 && l2) {
            ListNode* p = l1->val > l2->val ? l2 : l1;//设定头
            if (p == l1) {//若为l1，则向后走
                l1 = l1->next;
            }
            else {//否则l2往后走一位
                l2 = l2->next;
            }
            if (head == nullptr) {//若head为空，则将其指向p，将cur也指向p
                head = p;
                cur = p;
            }
            else {//等遍历到第二个结点的时候，将p依次插入到cur后面
                cur->next = p;
                cur = cur->next;
            }
        }
        if (l1 != nullptr) {//这里判断是否排完
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }
        return head;
    }
};