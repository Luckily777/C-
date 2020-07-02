#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    size_t pos;
    while ((pos = str.rfind(' ')) != -1){
        string str2 = str.substr(pos + 1, str.size() - pos - 1);
        cout << str2 << " ";
        str.erase(pos);
    }
    cout << str << endl;
    return 0;
}