//¿ÍËÆÔÆÀ´
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    vector<long> Food(81, 0);
//    Food[1] = 1;
//    for (int i = 2; i < 81; i++) {
//        Food[i] = Food[i - 1] + Food[i - 2];
//    }
//    int from;
//    int to;
//    while (cin >> from >> to) {
//        long  count = 0;
//        for (int i = from; i <= to; i++) {
//            count += Food[i];
//        }
//        cout << count << endl;
//    }
//    return 0;
//}