#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int64 N, M;
int64 Arr[100005];
int64 segTree[1000000]; //index

inline int64 searchTree(int64 start, int64 end, int64 curN, int64 left, int64 right) {
	int64 half = (start + end) / 2;
	int64 leftN = curN * 2;
	int64 rightN = curN * 2 + 1;

	if (start > right || left > end) return 100002;
	if (start >= left && right >= end) return segTree[curN];

	int64 a = searchTree(start, half, leftN, left, right);
	int64 b = searchTree(half + 1, end, rightN, left, right);

	if (Arr[a] == Arr[b]) {
		return a > b ? b : a;
	}

	return Arr[a] > Arr[b] ? b : a;
}

inline void updateTree(int64 start, int64 end, int64 curN, int64 chnN) {
	int64 half = (start + end) / 2;
	int64 leftN = curN * 2;
	int64 rightN = curN * 2 + 1;

	if (start <= chnN && end >= chnN && start != end) {

		updateTree(start, half, leftN, chnN);
		updateTree(half + 1, end, rightN, chnN);

		if (Arr[segTree[leftN]] == Arr[segTree[rightN]]) {
			segTree[curN] = segTree[leftN] > segTree[rightN] ? segTree[rightN] : segTree[leftN];
			return;
		}

		segTree[curN] = Arr[segTree[leftN]] > Arr[segTree[rightN]] ? segTree[rightN] : segTree[leftN];

	}
}

inline void initTree(int64 start, int64 end, int64 curN) {
	int64 half = (start + end) / 2;
	int64 leftN = curN * 2;
	int64 rightN = curN * 2 + 1;

	if (start == end) {
		segTree[curN] = start;
		return;
	}

	initTree(start, half, leftN);
	initTree(half + 1, end, rightN);

	if (Arr[segTree[leftN]] == Arr[segTree[rightN]]) {
		segTree[curN] = segTree[leftN] > segTree[rightN] ? segTree[rightN] : segTree[leftN];
		return;
	}

	segTree[curN] = Arr[segTree[leftN]] > Arr[segTree[rightN]] ? segTree[rightN] : segTree[leftN];
}

int main() {
	fastio;

	Arr[100002] = INF;

	cin >> N;
	for (int64 i = 0; i < N; ++i) {
		cin >> Arr[i];
	}

	initTree(0, N - 1, 1);

	cin >> M;
	for (int64 i = 0; i < M; ++i) {
		int64 q, a, b;
		cin >> q >> a >> b;

		if (q == 1) {
			Arr[a - 1] = b;
			updateTree(0, N - 1, 1, a - 1);
		}
		else {
			cout << searchTree(0, N - 1, 1, a - 1, b - 1) + 1 << "\n";
		}
	}

	return EXIT_SUCCESS;
}