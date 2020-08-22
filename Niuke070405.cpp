//二叉搜索树和双向链表

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
            //左子树
            _Convert(root->left, prev);
            //处理当前节点
            root->left = *prev;
            if (*prev)
                (*prev)->right = root;
            *prev = root;
            //右子树
            _Convert(root->right, prev);
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* prev = nullptr;
        TreeNode* root = pRootOfTree;
        _Convert(root, &prev);
        //找到最左节点
        while (root && root->left)
            root = root->left;
        return root;
    }
};