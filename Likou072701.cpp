//class Solution
//
//{
//
//public:
//
//
//
//    void MulItem(string& tmp, string& num1, char a)
//
//    {
//
//        int i = 0, sign = 0;
//
//        int mul = 0;
//
//        while (i < num1.size())
//
//        {
//
//            mul = (num1[i] - '0') * (a - '0') + sign;
//
//            if (mul >= 10)
//
//            {
//
//                sign = mul / 10;
//
//                mul %= 10;
//
//            }
//
//            else
//
//                sign = 0;
//
//            tmp.push_back(mul + '0');
//
//            i++;
//
//        }
//
//        if (sign > 0)
//
//            tmp.push_back(sign + '0');
//
//    }
//
//    //��ӦΪ��ӣ�sign��λ�������ô���
//
//    int AddItem(int a, int b, int& sign)
//
//    {
//
//        int add = a + b + sign;
//
//        if (add >= 10)
//
//        {
//
//            sign = 1;
//
//            add -= 10;
//
//        }
//
//        else
//
//            sign = 0;
//
//        return add;
//
//    }
//
//    //��λ���
//
//    void MoveAdd(string& result, string& tmp, int k)
//
//    {
//
//        int i, j;
//
//        i = k;
//
//        j = 0;
//
//        int sign = 0;
//
//        while (i < result.size() && j < tmp.size())
//
//        {
//
//            result[i] = AddItem(result[i] - '0', tmp[j] - '0', sign) + '0';
//
//            i++;
//
//            j++;
//
//        }
//
//        while (i < result.size() && sign)
//
//        {
//
//            result[i] = AddItem(result[i] - '0', 0, sign) + '0';
//
//            i++;
//
//        }
//
//        while (j < tmp.size())
//
//        {
//
//            int v = AddItem(0, tmp[j] - '0', sign);
//
//            result.push_back(v + '0');
//
//            j++;
//
//        }
//
//        if (sign)
//
//            result.push_back(sign + '0');
//
//    }
//
//
//
//    string multiply(string num1, string num2)
//
//    {
//
//        //�ȷ�ת���ݣ������λ����
//
//        reverse(num1.begin(), num1.end());
//
//        reverse(num2.begin(), num2.end());
//
//
//
//        string tmp, result;
//
//        for (int i = 0; i < num2.size(); ++i)
//
//        {
//
//            //ʹ��num2��ÿһ�����ݳ���num1
//
//            MulItem(tmp, num1, num2[i]);
//
//            //���˵õĽ�����д�λ���
//
//            MoveAdd(result, tmp, i);
//
//            tmp.clear();
//
//        }
//
//
//
//        while (result.size() != 1 && result.back() == '0')
//
//            result.pop_back();
//
//
//
//        //��ת���ݣ��ָ�����
//
//        reverse(result.begin(), result.end());
//
//        return result;
//
//    }
//
//};