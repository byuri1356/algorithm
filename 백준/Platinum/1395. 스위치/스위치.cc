#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

inline void updateLazy(vector<int>& tree, vector<bool>& lazy, int start, int end, int node) {
	if (lazy[node]) {
		tree[node] = end - start + 1 - tree[node];

		lazy[node] = false;

		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
	}
}

inline int findTree(vector<int>& tree, vector<bool>& lazy, int start, int end, int node, int left, int right) {
	updateLazy(tree, lazy, start, end, node);

	if (right < start || left > end) return 0;

	if (left <= start && right >= end) {
		return tree[node];
	}

	int half = (start + end) / 2;
	int lt = findTree(tree, lazy, start, half, node * 2, left, right);
	int rt = findTree(tree, lazy, half + 1, end, node * 2 + 1, left, right);

	return lt + rt;
}

inline void updateTree(vector<int>& tree, vector<bool>& lazy, int start, int end, int node, int left, int right) {
	updateLazy(tree, lazy, start, end, node);

	if (right < start || left > end) return;

	if (left <= start && right >= end) {
		tree[node] = end - start + 1 - tree[node];

		if (start != end) {
			lazy[node*2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}

	int half = (start + end) / 2;

	updateTree(tree, lazy, start, half, node * 2, left, right);
	updateTree(tree, lazy, half + 1, end, node * 2 + 1, left, right);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int main() {

	fastio;

	int N, M, H, treeSize;
	cin >> N >> M;

	H = (int)ceil(log2(N));
	treeSize = 1 << (H + 1);

	vector<int> tree(treeSize);
	vector<bool> lazy(treeSize);

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {
			updateTree(tree, lazy, 1, N, 1, b, c);
		}
		else {
			cout << findTree(tree, lazy, 1, N, 1, b, c) << "\n";
		}
	}

	return EXIT_SUCCESS;
}