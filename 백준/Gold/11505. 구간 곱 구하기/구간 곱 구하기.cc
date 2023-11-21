#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int64 N, M, K;
int64 Arr[1000000];
int64 sTree[4000000];
int64 div_n = 1000000007;

inline int64 mul(int64 start, int64 end, int64 node, int64 left, int64 right) {
	int64 half = (start + end) / 2;

	if (right < start || left > end) return 1;
	else if (start >= left && end <= right) return sTree[node];

	return ((mul(start, half, node * 2, left, right) % div_n) * (mul(half + 1, end, node * 2 + 1, left, right) % div_n)) % div_n; 
}

inline int64 update(int64 start, int64 end, int64 node, int64 change, int64 num) {
	int64 half = (start + end) / 2;
	if (start == end && start == change) return sTree[node] = num;
	if (start <= change && end >= change) {
		if (start != end) {
			sTree[node] = ((update(start, half, node * 2, change, num) % div_n) * (update(half + 1, end, node * 2 + 1, change, num) % div_n)) % div_n;
		}
	}

	return sTree[node];
}

inline int64 init(int64 start, int64 end, int64 node) {
	int64 half = (start + end) / 2;

	if (start == end) return sTree[node] = Arr[start];
	return sTree[node] = ((init(start, half, node * 2) % div_n) * (init(half + 1, end, node * 2 + 1) % div_n)) % div_n;
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
			update(0, N - 1, 1, b - 1, c);
		}
		else {
			cout << mul(0, N - 1, 1, b - 1, c - 1) % div_n << "\n";
		}
	}

	return EXIT_SUCCESS;
}