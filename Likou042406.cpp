572. ��һ����������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL && p == NULL)
        return true;
    //û��ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL || p == NULL)
        return false;
    // ��Ӧλ�õ�ֵ�Լ��ӽṹ�Ƿ���ͬ
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    //�κ�������������
    if (t == NULL)
        return true;
    //�����������ǿյ���
    if (s == NULL)
        return false;

    if (isSameTree(s, t))
        return true;
    //�ж����������Ƿ������ͬ�Ľṹ
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}