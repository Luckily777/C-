ţ��:����Ļ��Ľṹ
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* slow, * fast, * prev, * cur, * next;
        if (A == NULL || A->next == NULL)
            return true;
        /*
        //�ҵ��м�ڵ�
        fast = slow = A;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //��ת
        prev = NULL;
        cur = slow;
        while(cur)
        {

            next = cur->next;
            //ͷ��
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur = prev;
        //�Ƚ�
        while(A && cur)
        {
            if(A->val != cur->val)
                return false;
            A = A->next;
            cur = cur->next;
        }
        return true;
        */
        //��һ�������ռ������
        int array[900];
        cur = A;
        int idx = 0;
        while (cur)
        {
            array[idx++] = cur->val;
            cur = cur->next;
        }
        //�����жϻ���
        int start = 0;
        int end = idx - 1;
        while (start < end)
        {
            if (array[start] != array[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};