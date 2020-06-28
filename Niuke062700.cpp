//神奇的数字
#include <iostream>
#include <string>
using namespace std;

int main() {
	string number("12346");
    string::iterator itbegin = number.begin();
    string::iterator itend = (number.end())-1;
    while (itbegin < itend) {
        while ((*itbegin - '0') % 2 != 0) {
            itbegin++;
        }
        while ((*itend- '0') % 2 != 0) {
            itend--;
        }
        if(itbegin<itend){
            swap(*itbegin, *itend);
            itbegin++;
            itend--;
        }
    }
    return number;
}


//多种解决方法

int lsize = 0;
int rsize = number.length() - 1;
while (lsize < rsize) {
    if ((number[lsize] - '0') % 2 == 0) {
        if ((number[rsize] - '0') % 2 == 0) {
            swap(number[lsize++], number[rsize--]);
        }
    }
}
cout << number << endl;