ɾ���������ظ��Ľ��

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        struct ListNode* cur, * perv, * bol, * temp;
        //����ָ�����
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
            //�пգ�������ָ��ջ�ֻ��һ��Ԫ�� �򷵻�������׵�ַ
        }
        perv = NULL;
        //pervָ���
        cur = pHead;
        //curָ��������׵�ַ

        bol = cur->next;
        //bolָ��cur��next��ַ
        while (bol) {
            //�ж�bol��Ϊ�յ�ʱ���������Ĳ���
            if (bol->val == cur->val) {
                //��bol������ݺ�cur��ָ���������������½���
                while (bol && bol->val == cur->val) {
                    //�ж�bol�Ƿ�Ϊ�գ����ұ�֤bol��ָ��Ԫ�ص���cur��ָ���Ԫ��
                    bol = bol->next;
                    //��bol����һλ
                }
                while (cur != bol) {
                    //���cur������bol�ˣ����пռ���ͷ�
                    temp = cur->next;
                    //��cur��next��ַ�������м����temp֮��
                    free(cur);
                    //�ͷ�cur
                    cur = temp;
                    //���¸�cur��ֵ
                }
                if (perv == NULL) {
                    //�ж�ɾ�����Ƿ�Ϊ�׵�ַ
                    pHead = cur;
                    //��cur���¸����׵�ַ
                }
                else {
                    perv->next = cur;
                    //����perv��nextֱ��ָ��cur��λ��
                }
                if (bol) {
                    //��bol��Ϊ��
                    bol = bol->next;
                    //���������ƶ�
                }
            }
            else {
                //���� ����ָ��ȫ������˳��һλ
                perv = cur;
                cur = bol;
                bol = bol->next;
            }
        }
        return pHead;
    }
};