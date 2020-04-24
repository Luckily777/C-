572. 另一个树的子树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //同时走到空， 结构相同
    if (q == NULL && p == NULL)
        return true;
    //没有同时走到空， 结构不同
    if (q == NULL || p == NULL)
        return false;
    // 对应位置的值以及子结构是否相同
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    //任何树都包含空树
    if (t == NULL)
        return true;
    //空树不包含非空的树
    if (s == NULL)
        return false;

    if (isSameTree(s, t))
        return true;
    //判断左右子树是否包含相同的结构
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}