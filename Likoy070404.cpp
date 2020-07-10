//236. 二叉树的最近公共祖先

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//使用栈
class Solution {
public:

    bool getPath(TreeNode* root, TreeNode* cur, stack<TreeNode*>& st) {
        if (root == nullptr) {
            return false;
        }
        st.push(root);
        if (root == cur)
            return true;
        if (getPath(root->left, cur, st))
            return true;
        if (getPath(root->right, cur, st))
            return true;
        st.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path1;
        stack<TreeNode*> path2;
        getPath(root, p, path1);
        getPath(root, q, path2);

        //路径的裁剪
        while (path1.size() != path2.size()) {
            if (path1.size() > path2.size())
                path1.pop();
            else
                path2.pop();
        }

        //找最近公共祖先
        while (!path1.empty()) {
            if (path1.top() == path2.top())
                return path1.top();
            else {
                path1.pop();
                path2.pop();
            }
        }
        return 0;
    }
};

//队列

class Solution {
public:

    bool getPath(TreeNode* root, TreeNode* cur, deque<TreeNode*>& st) {
        if (root == nullptr) {
            return false;
        }
        st.push_back(root);
        if (root == cur)
            return true;
        if (getPath(root->left, cur, st))
            return true;
        if (getPath(root->right, cur, st))
            return true;
        st.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> path1;
        deque<TreeNode*> path2;
        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode* ret;
        //找最近公共祖先
        while (!path1.empty()) {
            if (path1.front() == path2.front()) {
                ret = path1.front();
                path1.pop_front();
                path2.pop_front();
            }
            else {
                break;
            }
        }
        return ret;
    }
};