ţ�ͣ�����Ļ��Ľṹ

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
        struct ListNode* slow, * fast;
        //��������ָ���������м�λ�õ�Ѱ��
        if (A == NULL || A->next == NULL) {
            return true;
            //�ж������������Ƿ�Ϊ�ջ���Ϊ��һ����
        }
        slow = A;
        fast = A;
        //����ָ���ʼ����ʹ��ָ������A�ĵ�ַ
        while (fast && fast->next) {
            slow = slow->next;
            //��ָ���ƶ�һ��
            fast = fast->next->next;
            //��ָ���ƶ�������ʹ�õ���ָ������ĩβ��ʱ����ָ��պ��ߵ��м�λ��
        }
        struct ListNode* cur, * perv;
        perv = NULL;
        //�����м��������ָ��
        cur = slow;
        //�����ƶ���ָ��ָ���м�λ��
        struct ListNode* next;
        while (cur) {
            next = cur->next;
            //����һ��λ�õĵ�ַ������next֮��
            cur->next = perv;
            //����ָ��perv������cur��next֮��
            perv = cur;
            //�ٴθ���perv�����µ�ֵ
            cur = next;
            //��������next֮�еĵ�ַ��cur
        }
        cur = perv;

        //������λ�����¸����cur
        //�Ƚ�Ԫ��
        while (A && cur) {
            if (A->val != cur->val) {
                return false;
            }
            A = A->next;
            //ȫ������
            cur = cur->next;
        }
        free(perv);
        //�ͷ�����ָ��
        free(next);
        return true;
    }
};