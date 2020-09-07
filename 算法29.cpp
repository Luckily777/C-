//二叉树的深度


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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr) {
            return 0;
        }
        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};



//递归

class Solution {
public:

    static void TreeDepthHelper(TreeNode* root, int depth, int& max) {
        if (root == nullptr) {
            if (max < depth) {
                max = depth;
            }
            return;
        }
        TreeDepthHelper(root->left, depth + 1, max);
        TreeDepthHelper(root->right, depth + 1, max);
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr) {
            return 0;
        }
        int max = 0;
        int depth = 0;
        TreeDepthHelper(pRoot, depth, max);
        return max;
    }
};