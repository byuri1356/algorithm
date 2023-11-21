#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;
//BOJ_9251_G5_LCS
//5940KB, 4ms

int N, M, a[100][100], b[100][100];

int main() {
	fastio;
	
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << a[i][j] + b[i][j] << ' ';
		}
		cout << "\n";
	}

	return EXIT_SUCCESS;
}