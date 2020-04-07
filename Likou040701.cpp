141. ��������

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
        //�趨����ָ�������в���
        if (head == NULL) {
            //�����п�
            return false;
        }
        fast = slow = head;
        //�ÿ���ָ��ȫ��ָ������ͷ��ַ
        while (fast && fast->next) {
            //��ָ����ָ��ĵ�ַ��Ϊ��
            fast = fast->next->next;
            //��ָ�����������
            slow = slow->next;
            //��ָ�������һ��
            if (slow == fast) {
                //������������ȷ
                return true;
            }
        }
        return false;
    }
};