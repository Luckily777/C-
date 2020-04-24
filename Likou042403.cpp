226. ��ת������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _invert(struct TreeNode* root)
{
    if (root)
    {
        //��ת���Һ���
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        //���ҽ��н���
        //������ת
        _invert(root->left);
        _invert(root->right);
        //�ٽ������������н���
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    _invert(root);
    return root;
}