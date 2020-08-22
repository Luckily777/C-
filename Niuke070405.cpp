//������������˫������

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void _Convert(TreeNode* root, TreeNode** prev) {
        if (root) {
            //������
            _Convert(root->left, prev);
            //����ǰ�ڵ�
            root->left = *prev;
            if (*prev)
                (*prev)->right = root;
            *prev = root;
            //������
            _Convert(root->right, prev);
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* prev = nullptr;
        TreeNode* root = pRootOfTree;
        _Convert(root, &prev);
        //�ҵ�����ڵ�
        while (root && root->left)
            root = root->left;
        return root;
    }
};