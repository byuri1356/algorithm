#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 initTree(vector<int64>& tree, vector<int64>&arr, int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];

	int half = (start + end) / 2;
	return tree[node] = initTree(tree, arr, start, half, node * 2) + initTree(tree, arr, half + 1, end, node * 2 + 1);
}

void updateLazy(vector<int64>& tree, vector<int64>&lazy, int start, int end, int node) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		
		lazy[node] = 0;
	}
}

void updateTree(vector<int64>& tree, vector<int64>& lazy, int start, int end, int node, int left, int right, int64 diff) {
	updateLazy(tree, lazy, start, end, node);

	if (start > right || end < left) return;

	if (start >= left && end <= right) {
		tree[node] += (end - start + 1) * diff;

		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
	
		return;
	}

	int half = (start + end) / 2;
	updateTree(tree, lazy, start, half, node * 2, left, right, diff);
	updateTree(tree, lazy, half + 1, end, node * 2 + 1, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int64 findTree(vector<int64>& tree, vector<int64>& lazy, int start, int end, int node, int left, int right) {
	updateLazy(tree, lazy, start, end, node);

	if (start > right || end < left) return 0;

	if (start >= left && end <= right) return tree[node];

	int half = (start + end) / 2;
	int64 lf = findTree(tree, lazy, start, half, node * 2, left, right);
	int64 rt = findTree(tree, lazy, half + 1, end, node * 2 + 1, left, right);

	return lf + rt;
}

int main() {

	fastio;

	int N, M, K;
	cin >> N >> M >> K;
	M += K;

	int h = (int)ceil(log2(N));
	int ts = 1 << (h + 1);

	vector<int64> tree(ts), lazy(ts), arr(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	initTree(tree, arr, 1, N, 1);

	while (M--) {
		int a, b, c;
		int64 d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			updateTree(tree, lazy, 1, N, 1, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << findTree(tree, lazy, 1, N, 1, b, c) << "\n";
		}
	}

	return EXIT_SUCCESS;
}