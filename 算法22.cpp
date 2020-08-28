//�������к�Ϊĳһֵ��·��

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
        list.push_back(root->val);//��������뵽��ѡ
        expectNumber -= root->val;//��֦
        if (root->left == nullptr && root->right == nullptr && expectNumber == 0) {
            result.push_back(list);//��������뵽�����
        }

        FindPathFDS(root->left, expectNumber, result, list);//���
        FindPathFDS(root->right, expectNumber, result, list);//�ұ�

        list.pop_back();//����
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