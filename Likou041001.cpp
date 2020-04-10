147. ��������в�������

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
    ListNode* insertionSortList(ListNode* head) {
        struct ListNode* cur, * pevr, * start;
        //�������ָ�����
        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        //�����µ�һ��ͷ�ռ䣬��ʾ����ǰ�������ͷ
        if (head == NULL || head->next == NULL) {
            //�пղ���
            return head;
        }
        NewHead->next = head;
        //��ԭ�е�����ͷ�������������ͷnext��ַ֮��
        pevr = head;
        //pevrָ��ָ��ԭ�е�ͷ����
        cur = head->next;
        //curָ������ͷ��nextλ��
        while (cur) {
            //��ʼѭ��
            if (cur->val >= pevr->val) {
                //�����һ���ֵ���ڵ���ǰһ��ֵ
                pevr = cur;
                //ԭ�ز��䣬��pevr��cur����ƶ�һλ
                cur = cur->next;
            }
            else {
                //��������������в���
                start = NewHead;
                //startָ��ָ�������������ͷָ��
                while (start->next && start->next->val <= cur->val) {
                    //��ͷ����֮�����һλֵС�ڵ�����һ���ֵ��ֱ��˳��
                    start = start->next;
                }
                pevr->next = cur->next;
                //��cur֮�е�next��ָ��ĵ�ַ����pevr��next֮��
                cur->next = start->next;
                //��start��next��ַҲ����һ��ʼ��head��ַ����cur��next֮��
                start->next = cur;
                //��cur�ĵ�ַ����strar��next��ַ
                cur = pevr->next;
                ///pevr��next��ַ����cur
            }
        }
        cur = NewHead->next;
        //���½�NewHead��next��ַ����cur
        free(NewHead);
        //�ͷ�������ı���
        return cur;
        //����cur �ĵ�ַ
    }
};