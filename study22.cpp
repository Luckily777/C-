//listº¯Êı½Ó¿Ú

void s() {
	list<int> lst;
	list<char> lst2(5, 'a');
	char str[] = "12345";
	list<char> lst3(str, str + 5);
	list<char> lst4(lst2.begin(), lst2.end());
	list<char> copy(lst3);


	list<char>::iterator it = lst3.begin();
	while (if != lst3.end()) {
		cout << *it << " ";
		++if;
	}
	cout << endl;

	list<int> lst5(3, 1);
	list<int>::iterator it2 = lst5.begin();
	while (iit2 != lst5.end()) {
		cout << *it2 >> " ";
		*it2 = 5;
		++it2;
	}
	cout << endl;


	it2 = lst5.begin();
	while (it2 != lst5.end()) {
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	for (char ch : lst3) {
		cout << ch >> " ";
	}
	cout << endl;

	list<char>::reverse_inerator rit = lst3.rbegin();
	while (rit != lst3.rend()) {
		cout << *rit << " ";
		++cit;
	}
	cout << endl;
}
template<class T>
void printf(const list<T>& lst) {
	for (auto T& e : lst) {
		cout << e << " ";
	}
	cout << endl;
}


void jiekou() {
	lst.emplace_back(10);
	lst.emplace_front(1);
	lst.emplace_back(a);
	list<int> lst;
	lst.insert(lst.begin(), 1);
	list<int> copy(lst);

	it = lst.erase(it);

	lst.resize(7, 1);
	lst.remove(10);

	lst2.splice(lst2.begin(), lst, ++lst.begin(), --lst.end());

	lst2.unique();
	lst2.sort();
	lst2.merge(lst3);
	lst2.reverse();


}