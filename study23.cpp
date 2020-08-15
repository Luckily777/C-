//stack
template <class T,class Container =deque<T>>
class Stack {
public:
	void push(const T& val) {
		_c.push_back(val);
	}

	void pop() {
		_c.pop_back();
	}

	const T& top() {
		return _c.back();
	}

	size_t size() const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty;
	}

private:
	Container _c;
};


//deque

template <class T,class Container=deque<T>>
class Queue {
public:
	void push(const T& val) {
		_c.push_back(val);
	}

	void pop() {
		_c.pop_front();
	}

	T& front() {
		return _c.front;
	}

	T& back() {
		return _c.back();
	}

	size_t size() const{
		return _c.size();
	}

	bool empty() const{
		return _c.empty();
	}
private:
	Container _c;
};

//优先队列
template <class T>
struct Greater {
	bool operator()(const T& val1, const T& val2) {
		return val1 > val2;
	}
};

template <class T>
struct Less {
	bool operator()(const T& val1, const T& val2) {
		return val1 < val2;
	}
};

template <class T,class Container =vector<T>,class Compare=Less<T>>
class Priority_queue {
public:
	void push(const T& val) {
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop() {
		Swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top() {
		return _c.front();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}
private:
	Container _c;
	Compare _cmp;
};