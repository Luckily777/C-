//topK ʹ�����ȶ��еķ�ʽ��ʵ��
class Solution {
public:
    struct comp {
        bool operator()(const int& a, const int& b) {
            return a < b;//����С������ѣ����ʹ�ý���
        }
    };
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> list;
        if (k <= 0 || input.size() == 0 || input.size() < k) {//�������ٽ����
            return list;
        }
        priority_queue<int, vector<int>, comp> q;//���䱣����vector��
        for (int i = 0; i < input.size(); i++) {
            if (i < k) {//��һ���Խ�ǰk��ȫ��װ��ȥ
                q.push(input[i]);
            }
            else {
                if (input[i] < q.top()) {//���ҶѶ�Ԫ�غ���һ��Ԫ�صĴ�С
                    q.pop();//ɾ���Ѷ�Ԫ��
                    q.push(input[i]);//��С������ֵ�����ȥ
                }
            }
        }
        for (int i = 0; i < k; i++) {
            list.push_back(q.top());//����ǰk��ȫ�������list֮��
            q.pop();//ɾ���Ѷ�
        }
        return list;
    }
};