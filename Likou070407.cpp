//106. 从中序与后序遍历序列构造二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* preBuildTree(vector<int>& preorder, int* preIdx, vector<int>& inorder, int startIdx, int endIdx) {
        if (startIdx > endIdx) {
            return nullptr;
        }
        //创建当前节点
        TreeNode* root = new TreeNode(preorder[*preIdx]);
        //左右子树区间
        int rootIdx = startIdx;
        for (; rootIdx <= endIdx; ++rootIdx) {
            if (root->val == inorder[rootIdx])
                break;
        }
        //构建右子树
        if (rootIdx < endIdx) {
            --(*preIdx);
            root->right = preBuildTree(preorder, preIdx, inorder, rootIdx + 1, endIdx);
        }
        else
            root->right = nullptr;
        //构建左子树
        if (startIdx < rootIdx) {
            --(*preIdx);
            root->left = preBuildTree(preorder, preIdx, inorder, startIdx, rootIdx - 1);
        }
        else
            root->left = nullptr;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) {
            return nullptr;
        }
        int postIdx = postorder.size() - 1;
        return preBuildTree(postorder, &postIdx, inorder, 0, inorder.size() - 1);
    }
};