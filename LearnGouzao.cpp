#include <iostream>
using namespace std;
//
//class Widget
//{
//public:
//	Widget(int a=1) {
//		_a = a;
//		cout << "gouzao" << endl;
//	}
//
//	Widget(const Widget& d) {
//		_a = d._a;
//		cout << "kaobei" << endl;
//	}
//private:
//	int _a;
//};
//
//Widget f(Widget u) {
//	Widget v(u);
//	Widget w = v;
//	return w;
//}
//
//int main() {
//	Widget x;
//	Widget y = f(f(x));
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class parent
//{
//	int i;
//protected:
//	int x;
//public:
//	parent() { x = 0; i = 0; }
//	void change() { x++; i++; }
//	void display();
//};
//class son :public parent
//{
//public:
//	void modify();
//};
//void parent::display() { cout << "x=" << x << endl; }
//void son::modify() { x++; }
//int main()
//{
//	son A; parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();
//	B.display();
//}