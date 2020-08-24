//��ͷ��β��ӡ����
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//1. ʹ��ջ
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> st;
        vector<int> vt;
        while (head) {
            st.push(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            vt.push_back(st.top());
            st.pop();
        }
        return vt;
    }
};

//2. ���ã�ʹ��vectorֱ�ӱ���������
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vt;
        while (head) {
            vt.push_back(head->val);
            head = head->next;
        }
        reverse(vt.begin(), vt.end());
        return vt;
    }
};



//�ݹ鷽ʽ


void printList(ListNode* head, vector<int>& vt) {
    if (head == nullptr) {
        return;
    }
    printList(head->next, vt);
    vt.push_back(head->val);
}
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vt;
        printList(head, vt);
        return vt;
    }
};