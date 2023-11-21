#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int64 N, M, K;
int64 Arr[1000000];
int64 sTree[4000000];

inline int64 sum(int64 start, int64 end, int64 node, int64 left, int64 right) {
	int64 half = (start + end) / 2;
	if (right < start || left > end) return 0;
	else if (start >= left && end <= right) return sTree[node];
	else {	
		return sum(start, half, node * 2, left, right) + sum(half + 1, end, node * 2 + 1, left, right);
	}

	return 0;
}

inline void update(int64 start, int64 end, int64 node, int64 change, int64 diff) {
	int64 half = (start + end) / 2;
	if (start <= change && end >= change) {
		sTree[node] += diff;
		if (start != end) {
			update(start, half, node * 2, change, diff);
			update(half + 1, end, node * 2 + 1, change, diff);
		}
	}
}

inline int64 init(int64 start, int64 end, int64 node) {
	int64 half = (start + end) / 2;
	if (start == end) sTree[node] = Arr[start];
	else sTree[node] = init(start, half, node * 2) + init(half + 1, end, node * 2 + 1);
	
	return sTree[node];
}

int main() {
	fastio;

	cin >> N >> M >> K;
	for (int64 i = 0; i < N; ++i) {
		cin >> Arr[i];
	}

	init(0, N - 1, 1);

	for (int64 i = 0; i < M + K; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			int64 diff = c - Arr[b - 1];
			Arr[b - 1] = c;
			update(0, N - 1, 1, b - 1, diff);
		}
		else {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
		}
	}

	return EXIT_SUCCESS;
} 