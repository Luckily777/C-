138. ���ƴ����ָ�������

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return head;
            //�����пղ���
        }
        struct Node* cur, * next, * copy;
        //��������ָ�����
        //����
        cur = head;
        //��curָ��ָ��ͷ����
        while (cur) {
            //���Ʋ���
            next = cur->next;
            //����һ�������λ�ñ�����next��
            struct Node* Copy = (struct Node*)malloc(sizeof(struct Node));
            //��������һ���µ������С�ռ�
            Copy->val = cur->val;
            //�����е�����Ҳ���и���
            cur->next = Copy;
            //���¸��Ƶ������ַ����cur��next
            Copy->next = next;
            //��֮ǰ�������next��λ�ø���copy��next
            cur = next;
            //ʹ��cur���Ƶ�next
        }
        cur = head;
        //����ʹ��curָ�������ͷλ��
        while (cur) {
            //����random
            copy = cur->next;
            //��cur��nextλ�õĵ�ַ��copy
            next = copy->next;
            //��copy��ָ���next��ַ���浽next
            if (cur->random) {
                //����Ϊ�գ���random��ָ���Ƶ��¸��Ƶ�����֮�У�ʹ�����¸��Ƶ�ָ������¸��Ƶ�
                copy->random = cur->random->next;
            }
            else {
                copy->random = NULL;
                //����ָ��Ϊ��
            }
            cur = next;
            //ʹ��cur�ٴκ��Ƶ���ԭ����ĺ�һλ
        }
        cur = head;
        struct Node* NewHead = cur->next;
        //�����µ�����ָ�룬ָ��ڶ��������ַ
        while (cur) {
            copy = cur->next;
            //��cur��nextλ�ø���copy
            next = copy->next;
            //copy��next��ַλ�ñ�����next֮��
            cur->next = next;
            //next���赽cur��next֮��
            if (next) {
                //��next����һ���������copy��next
                copy->next = next->next;
            }
            cur = next;
            //ͬ��
        }
        return NewHead;
        //���ز���������������λ
    }
};