//¿ªÉ¢ÁÐ±éÀú

template <class K>
struct KeyOfvalue {
	const K& operator()(const K& key) {
		return key;
	}
};


template <class V>
struct HashNode {
	v _value;
	HashNode<V>* _next;

	HashNode(const V& val=V())
		:_value(val)
		,_next(nullptr)
	{}
};

