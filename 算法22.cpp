//二叉树中和为某一值的路径

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
    void FindPathFDS(TreeNode* root, int expectNumber, vector<vector<int> >& result, vector<int>& list) {
        if (root == nullptr) {
            return;
        }
        list.push_back(root->val);//将结果加入到待选
        expectNumber -= root->val;//剪枝
        if (root->left == nullptr && root->right == nullptr && expectNumber == 0) {
            result.push_back(list);//将结果加入到结果集
        }

        FindPathFDS(root->left, expectNumber, result, list);//左边
        FindPathFDS(root->right, expectNumber, result, list);//右边

        list.pop_back();//回退
    }

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<int> list;
        FindPathFDS(root, expectNumber, result, list);
        return result;
    }
};