#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using vvi = vector<vector<int>>;

int N, M;

inline int find(vvi& segTree, int st, int ed, int nd, int lt, int rt, int pv) {
	if (rt < st || ed < lt) return 0;

	if (lt <= st && ed <= rt) {
		return segTree[nd].size() - (upper_bound(segTree[nd].begin(), segTree[nd].end(), pv) - segTree[nd].begin());
	}

	int hf = (st + ed) / 2;
	
	return find(segTree, st, hf, nd * 2, lt, rt, pv) + find(segTree, hf + 1, ed, nd * 2 + 1, lt, rt, pv);
}

inline void init(vvi& segTree, vector<int>& arr, int st, int ed, int nd) {
	int sz = ed - st + 1;
	segTree[nd].resize(sz);

	if (st == ed) {
		segTree[nd][0] = arr[st];
		return;
	}

	int hf = (st + ed) / 2;

	init(segTree, arr, st, hf, nd * 2);
	init(segTree, arr, hf + 1, ed, nd * 2 + 1);

	int lsz = segTree[nd * 2].size();
	int rsz = segTree[nd * 2 + 1].size();

	for (int i = 0, l = 0, r = 0; i < sz; ++i) {
		if (r >= rsz) segTree[nd][i] = segTree[nd * 2][l++];
		else if (l >= lsz) segTree[nd][i] = segTree[nd * 2 + 1][r++]; 
		else if (segTree[nd * 2][l] < segTree[nd * 2 + 1][r]) segTree[nd][i] = segTree[nd * 2][l++];
		else segTree[nd][i] = segTree[nd * 2 + 1][r++];
	}
}

int main() {

	fastio;

	cin >> N;

	int h = ceil(log2(N));
	int sz = 1 << (h + 1);

	vector<int> arr(N + 1);
	vvi segTree(sz);

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	init(segTree, arr, 1, N, 1);

	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << find(segTree, 1, N, 1, a, b, c) << "\n";
	}

	return EXIT_SUCCESS;
}