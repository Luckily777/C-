138. ���ƴ����ָ�������

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur, * copy, * next, * newH;
    if (head == NULL)
        return head;
    //�����ڵ�
    cur = head;
    while (cur)
    {
        next = cur->next;
        //�����ڵ�
        copy = (struct Node*) malloc(sizeof(struct Node));
        copy->val = cur->val;
        //����   cur, copy, next

        cur->next = copy;
        copy->next = next;

        cur = next;
    }
    //����random
    cur = head;
    while (cur)
    {
        copy = cur->next;
        next = copy->next;

        if (cur->random)
            copy->random = cur->random->next;
        else
            copy->random = NULL;

        cur = next;
    }

    //����
    cur = head;
    newH = cur->next;
    while (cur)
    {
        copy = cur->next;
        next = copy->next;

        cur->next = next;

        if (next)
            copy->next = next->next;

        cur = next;
    }
    return newH;
}
