//topK

//找最大的K个元素

void printtopK(int* a, int n, int k) {
	heap hp;
	heapinit(&hp, a, k);
	for (size_t i = k; i < n; i++) {
		if (a[i] > hearTop(&hp)) {
			heappop(&hp);
			heappush(&ph, a[i]);
		}
	}
}


//找最小的K元素

void printtopK(int* a, int n, int k) {
	heap hp;
	heapinit(&hp, a, k);
	for (sizeT i = k; i < n; i++) {
		if(a[i]<heaptop(&hp)){
			heappop(&hp);
			heappush(&hp, a[i]);
	}
}