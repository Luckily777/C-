//�����г��ִ�������һ�������


//1. ����map�㷨
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {//�����пգ���Ϊ����ֱ�ӷ���
            return 0;
        }
        unordered_map<int, int> m;//��������map
        int half = numbers.size() / 2;//����һ�����
        for (int i = 0; i < numbers.size(); i++) {
            auto it = m.find(numbers[i]);//��map�в��Ҵ����Ƿ����
            if (it == m.end()) {
                m.insert({ numbers[i],1 });//�������������
            }
            else {
                m[numbers[i]]++;//�����ڣ������++
            }
            if (m[numbers[i]] > half) {//������һ��ֵʱ����ֱ�Ӵ�ӡ����
                return numbers[i];
            }
        }
        return 0;
    }
};


//�ڱ��㷨

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {//�����пգ���Ϊ����ֱ�ӷ���
            return 0;
        }
        int result = numbers[0];//���������ڱ�
        int time = 1;//������Ϊ1
        for (int i = 1; i < numbers.size(); i++) {
            if (time == 0) {//������Ϊ0��������Ѿ�����
                result = numbers[i];//���µ�λ�ô���
                time = 0;
            }
            else if (result == numbers[i]) {//�����ڣ���time++
                time++;
            }
            else {
                time--;//�������
            }
        }

        time = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (result == numbers[i]) {
                time++;//֮�����±���result�Ĵ���
            }
        }
        return time > (numbers.size() / 2) ? result : 0;//����
        return 0;
    }
};