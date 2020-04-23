145. �������ĺ������


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
        //�пգ���Ϊ���������������Ĵ�СΪ0
        return 0;
    return getSize(root->left)
        + getSize(root->right) + 1;
    //�����������Ĵ�С����������+������+��
    //�Եݹ����ʽ����
}

void _postorderT(struct TreeNode* root, int* array, int* idx)
{
    if (root)
    {
        //������
        _postorderT(root->left, array, idx);
        //���������б���
        //������
        _postorderT(root->right, array, idx);
        //���������б���
        //��ǰ�ڵ�, ������ָ��
        array[*idx] = root->val;
        ++(*idx);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    //����������ڵ�
    *returnSize = 0;
    _postorderT(root, array, returnSize);
    return array;
}