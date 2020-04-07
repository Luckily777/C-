
��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

/*
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}; */
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* Lcur, * LcurN, * Gcur, * GcurN, * cur;
        Lcur = LcurN = (struct ListNode*)malloc(sizeof(struct ListNode));
        Gcur = GcurN = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (pHead == NULL) {
            return NULL;
        }
        cur = pHead;
        while (cur) {
            if (cur->val < x) {
                Lcur->next = cur;
                Lcur = Lcur->next;
            }
            else {
                Gcur->next = cur;
                Gcur = Gcur->next;
            }
            cur = cur->next;
        }
        Gcur->next = NULL;
        Lcur->next = GcurN->next;
        Lcur = LcurN;
        Gcur = GcurN;
        LcurN = LcurN->next;
        free(Lcur);
        free(Gcur);
        return LcurN;
    }
};