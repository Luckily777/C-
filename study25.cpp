//shard_ptr


template <class T,class deletor>
class sharedptr
{
public:
	sharedptr(T* ptr, deletor del)
		:_ptr(ptr)
		, _usecount(new int(1))
		, _mtx(new mutex)
		, _del(del)
	{

	}

	~sharedptr() {
		if (subRef() == 0) {
			del(_ptr);
			delete _usecount;
			delete _mtx;
		}
	}

	sharedptr(const sharedptr<T>& sp)
		:_ptr(sp._ptr)
		, _usecount(sp._usecount)
		, _mtx(sp._mtx) {
		addRed();
	}

	sharedptr<T>& operator=(const sharedptr<T>& sp) {
		if (_ptr != sp._ptr) {
			if (subRed() == 0) {
				delete _ptr;
				delete _usecount;
				delete _mtx;
			}

			_ptr = sp._ptr;
			_usecount = sp._usecount;
			_mtx = sp._mtx;
			addRef();
		}
		return *this;
	}

	int getusecount() {
		return *_usecount;
	}

	int addRef() {
		_mex->lock();
		++(*_usecount);
		_mtx->unlock();
		return *_usecount;
	}

	int subRef() {
		_mex->lock();
		--(*_usecount);
		_mtx->unlock();
		return *_usecount;
	}
private:
	T* _ptr;
	int* _usecount;
	mutex* _mtx;
	deletor _del;
};