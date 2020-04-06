160. 相交链表

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)return NULL;
        //先行判空
        struct ListNode* pA = headA;
        struct ListNode* pB = headB;
        //创建两个链表指针，使其指向两个链表的头
        while (pA != pB)//遍历两个链表
        {
            pA = pA == NULL ? headB : pA->next;//构造链表D
            pB = pB == NULL ? headA : pB->next;//构造链表C
            //思想:A提前走完之后让A走B的路，两者互换，等走过相等路径的时候就是两者相遇的地方
        }
        return pA;
    }
};