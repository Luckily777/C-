144. 二叉树的前序遍历


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

void _preorderT(struct TreeNode* root, int* array, int* idx)
{
    if (root)
    {
        //当前节点, 索引用指针
        array[*idx] = root->val;
        ++(*idx);
        //左子树
        _preorderT(root->left, array, idx);
        //右子树
        _preorderT(root->right, array, idx);

    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    //遍历，保存节点
    *returnSize = 0;
    _preorderT(root, array, returnSize);
    return array;
}