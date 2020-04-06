160. �ཻ����

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
        //�����п�
        struct ListNode* pA = headA;
        struct ListNode* pB = headB;
        //������������ָ�룬ʹ��ָ�����������ͷ
        while (pA != pB)//������������
        {
            pA = pA == NULL ? headB : pA->next;//��������D
            pB = pB == NULL ? headA : pB->next;//��������C
            //˼��:A��ǰ����֮����A��B��·�����߻��������߹����·����ʱ��������������ĵط�
        }
        return pA;
    }
};