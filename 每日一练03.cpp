//����������

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n + 1);//����һ��n+1�Ĵ�С�����ҽ�nλ����Ϊ0
    v[n] == 0;//���ｫ���һλ��Ϊ�㣬��Ϊ�˱������ֻʣ��һ��Ԫ�أ��޷ǽ��������ж�
    int i = 0;
    for (i = 0; i < n; i++) {
        cin >> v[i];//ѭ������
    }
    i = 0;
    int count = 0;
    while (i < n) {
        if (v[i + 1] > v[i]) {//�ǵݼ�����
            while (i < n && v[i + 1] >= v[i]) {
                i++;
            }//ѭ����������
            i++;
            count++;
        }
        else if (v[i + 1] == v[i]) {
            i++;//����Ȳ����ڵ���Ҳ�����ڵݼ���ֱ��i++
        }
        else {//�ǵ�������
            while (i < n && v[i] >= v[i + 1]) {
                i++;
            }//ѭ����������
            i++;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}