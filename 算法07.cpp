//ÖØ½¨¶þ²æÊ÷


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ReconstructBinarytree(vector<int> pre, int pre_start, int pre_end, vector<int> vin, int vin_start, int vin_end) {
        if (pre_start > pre_end || vin_start > vin_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pre_start]);
        for (int i = vin_start; i <= vin_end; i++) {
            if (vin[i] == pre[pre_start]) {
                root->left = ReconstructBinarytree(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
                root->right = ReconstructBinarytree(pre, pre_start + i - vin_start + 1, pre_end, vin, i + 1, vin_end);
                break;
            }
        }
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size()) {
            return nullptr;
        }
        return ReconstructBinarytree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};