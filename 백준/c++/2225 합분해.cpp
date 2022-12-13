#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[201][201];

inline int64 Solve(int64 N, int64 K) {
	if (arr[N][K]) return arr[N][K];

	for (int64 i = 0; i <= N; ++i) {
		if (arr[i][K - 1]) {
			arr[N][K] += arr[i][K - 1];
			arr[N][K] %= 1'000'000'000;
		}
		else {
			arr[N][K] += Solve(i, K - 1);
			arr[N][K] %= 1'000'000'000;
		}
	}
	return arr[N][K];
}

int main() {
	fastio;

	int64 N, K, Ans=0;
	cin >> N >> K;
	for (int64 i = 1; i < 201; ++i) {
		arr[0][i] = 1;
	}

	for (int64 i = 1; i <= N; ++i) {
		arr[i][1] = 1;
		arr[i][2] = i + 1;
	}

	Ans = Solve(N, K);
	cout << Ans % 1'000'000'000;;

	return EXIT_SUCCESS;
}