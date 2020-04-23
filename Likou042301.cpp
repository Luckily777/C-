145. 二叉树的后序遍历


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
        //判空，若为空则整个二叉树的大小为0
        return 0;
    return getSize(root->left)
        + getSize(root->right) + 1;
    //整个二叉树的大小等于左子树+右子树+根
    //以递归的形式进行
}

void _postorderT(struct TreeNode* root, int* array, int* idx)
{
    if (root)
    {
        //左子树
        _postorderT(root->left, array, idx);
        //左子树进行遍历
        //右子树
        _postorderT(root->right, array, idx);
        //右子树进行遍历
        //当前节点, 索引用指针
        array[*idx] = root->val;
        ++(*idx);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    //遍历，保存节点
    *returnSize = 0;
    _postorderT(root, array, returnSize);
    return array;
}