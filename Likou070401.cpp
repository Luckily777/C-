//606. 根据二叉树创建字符串

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
    void _tree2str(TreeNode* root, string& str) {
        if (root == nullptr) {
            return;
        }
        //处理当前节点
        stringstream ss;//整数转字符串
        ss << root->val;
        //字符串
        str += ss.str();
        //左子树
        if (root->left) {
            str += "(";
            _tree2str(root->left, str);
            str += ")";
        }
        else {
            if (root->right) {
                str += "()";
            }
            else {
                return;
            }
        }
        //右子树
        if (root->right) {
            str += "(";
            _tree2str(root->right, str);
            str += ")";
        }
        else {
            return;
        }
    }

    string tree2str(TreeNode* t) {
        string str;
        _tree2str(t, str);
        return str;
    }
};