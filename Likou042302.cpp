94. ���������������


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
        //������
        _inorderT(root->left, array, idx);

        //��ǰ�ڵ�, ������ָ��
        array[*idx] = root->val;
        ++(*idx);

        //������
        _inorderT(root->right, array, idx);

    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    //����������ڵ�
    *returnSize = 0;
    _inorderT(root, array, returnSize);
    return array;
}