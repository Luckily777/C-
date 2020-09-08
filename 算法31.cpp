//�������� ��Ϊs����������

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int low = 1;//��λ��start
        int hight = 2;//ĩλ��end
        while (low < hight) {//����
            int total = (hight + low) * (hight - low + 1) / 2;//�Ȳ�����
            if (sum == total) {//����ȣ���洢vector���ҽ�������������Ҫ�Ľ��
                vector<int> temp;
                for (int i = low; i <= hight; i++) {
                    temp.push_back(i);
                }
                result.push_back(temp);
                low++;//֮��ʹǰstartλ��++
            }
            else if (sum > total) {//��������endλ��++
                hight++;
            }
            else {//����startλ��++
                low++;
            }
        }
        return result;
    }
};