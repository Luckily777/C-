//�ϲ���������

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
     * @param l1 ListNode��
     * @param l2 ListNode��
     * @return ListNode��
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if (l1 == nullptr) {
            return l2;
        }//��l1Ϊ�գ���ֱ�ӷ���l2
        if (l2 == nullptr) {
            return l1;
        }//��l2Ϊ�գ���ֱ�ӷ���l1
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (l1 && l2) {
            ListNode* p = l1->val > l2->val ? l2 : l1;//�趨ͷ
            if (p == l1) {//��Ϊl1���������
                l1 = l1->next;
            }
            else {//����l2������һλ
                l2 = l2->next;
            }
            if (head == nullptr) {//��headΪ�գ�����ָ��p����curҲָ��p
                head = p;
                cur = p;
            }
            else {//�ȱ������ڶ�������ʱ�򣬽�p���β��뵽cur����
                cur->next = p;
                cur = cur->next;
            }
        }
        if (l1 != nullptr) {//�����ж��Ƿ�����
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }
        return head;
    }
};