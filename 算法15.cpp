//�����ӽṹ


//1. �ݹ�

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//class Solution {
//public:
//
//    bool Istreechild(TreeNode* root1, TreeNode* root2) {
//        if (root2 == nullptr) {//�����Ҫ�ҵ�Ϊ�գ���֤����������
//            return true;
//        }
//        if (root1 == nullptr) {//ĸ��Ϊ�գ���֤��û���꣬����false
//            return false;
//        }
//        if (root1->val != root2->val) {//�������������ȣ���Ҳ����false
//            return false;
//        }
//        return Istreechild(root1->left, root2->left) && Istreechild(root1->right, root2->right);//��Ҫ������ߵ������ȫ��ȣ����ж��ұߵ�
//    }
//
//    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//    {
//        if (pRoot1 == nullptr || pRoot2 == nullptr) {//�������һ����Ϊ���򷵻�false
//            return false;
//        }
//        bool result = false;
//        if (pRoot1->val == pRoot2->val) {//�����ڵ����
//            result = Istreechild(pRoot1, pRoot2);//��ֱ�����½��бȽ�
//        }
//        if (result != true) {
//            result = HasSubtree(pRoot1->left, pRoot2);//������ߵ��Ƿ����
//        }
//        if (result != true) {
//            result = HasSubtree(pRoot1->right, pRoot2);//���ұߵ��Ƿ����
//        }
//        return result;
//    }
//};