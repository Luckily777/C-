//Ìæ»»¿Õ¸ñ

class Solution {
public:
    void replaceSpace(char* str, int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                count++;
            }
        }
        int old_index = length;//¿¼ÂÇ\0
        int new_length = length + 2 * count;
        int new_index = new_length;
        while (new_index >= 0 && old_index >= 0) {
            if (str[old_index] == ' ') {
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
                old_index--;
            }
            else {
                str[new_index] = str[old_index];
                new_index--;
                old_index--;
            }
        }
    }
};