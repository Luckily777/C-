94. 二叉树的中序遍历


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getSize(root->left)
        + getSize(root->right) + 1;
}

void _inorderT(struct TreeNode* root, int* array, int* idx)
{
    if (root)
    {
        //左子树
        _inorderT(root->left, array, idx);

        //当前节点, 索引用指针
        array[*idx] = root->val;
        ++(*idx);

        //右子树
        _inorderT(root->right, array, idx);

    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    //遍历，保存节点
    *returnSize = 0;
    _inorderT(root, array, returnSize);
    return array;
}