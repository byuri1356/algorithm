#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int64 N, M;
int64 Arr[100000];
int64 minTree[400000];
int64 maxTree[400000];

inline int64 findMax(int64 start, int64 end, int64 node, int64 left, int64 right) {
	int64 half = (start + end) / 2;

	if (right < start || left > end) return 0;
	else if (left <= start && right >= end) return maxTree[node];

	return max(findMax(start, half, node * 2, left, right), findMax(half + 1, end, node * 2 + 1, left, right));
}

inline int64 findMin(int64 start, int64 end, int64 node, int64 left, int64 right) {
	int64 half = (start + end) / 2;

	if (right < start || left > end) return 1000000001;
	else if (left <= start && right >= end) return minTree[node];

	return min(findMin(start, half, node * 2, left, right), findMin(half + 1, end, node * 2 + 1, left, right));
}

inline int64 initMaxTree(int64 start, int64 end, int64 node) {
	int64 half = (start + end) / 2;
	if (start == end) return maxTree[node] = Arr[start];
	return maxTree[node] = max(initMaxTree(start, half, node * 2), initMaxTree(half + 1, end, node * 2 + 1));
}

inline int64 initMinTree(int64 start, int64 end, int64 node) {
	int64 half = (start + end) / 2;
	if (start == end) return minTree[node] = Arr[start];
	return minTree[node] = min(initMinTree(start, half, node * 2), initMinTree(half + 1, end, node * 2 + 1));
}

int main() {
	fastio;

	cin >> N >> M;

	for (int64 i = 0; i < N; ++i) {
		cin >> Arr[i];
	}

	initMaxTree(0, N - 1, 1);
	initMinTree(0, N - 1, 1);

	for (int64 i = 0; i < M; ++i) {
		int64 a, b;
		cin >> a >> b;

		cout << findMin(0, N - 1, 1, a - 1, b - 1) << " ";
		cout << findMax(0, N - 1, 1, a - 1, b - 1) << "\n";

	}

	return EXIT_SUCCESS;
}