牛客：链表分割

/*
2
struct ListNode {
3
    int val;
4
    struct ListNode *next;
5
    ListNode(int x) : val(x), next(NULL) {}
6
};*/
7
class Partition {
    8
public:
    9
        ListNode * partition(ListNode * pHead, int x) {
        10
            // write code here
            11
            struct ListNode* LH, * LT, * GH, * GT, * cur;
        12
            if (pHead == NULL)
                13
                return NULL;
        14
            LH = LT = (struct ListNode*) malloc(sizeof(struct ListNode));
        15
            GH = GT = (struct ListNode*) malloc(sizeof(struct ListNode));
        16
            cur = pHead;
        17
            while (cur)
                18
            {
                19
                    if (cur->val < x)
                        20
                    {
                        21
                            LT->next = cur;
                        22
                            LT = LT->next;
                        23
                    }
                24
                    else
                        25
                    {
                        26
                            GT->next = cur;
                        27
                            //可以这样写：GT = cur;
                            28
                            GT = GT->next;
                        29
                    }
                30
                    cur = cur->next;
                31
            }
        32
            GT->next = NULL;
        33
            LT->next = GH->next;
        34
            LT = LH;
        35
            GT = GH;
        36
            LH = LH->next;
        37
            //释放堆上空间
            38
            free(LT);
        39
            free(GT);
        40
            return LH;
        41
    }
    42
};