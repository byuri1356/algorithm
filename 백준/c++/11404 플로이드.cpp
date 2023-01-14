#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 arr[101][101];

int main() {
	fastio;

	int64 N, M;
	cin >> N >> M;

	for (int64 i = 1; i <= N; ++i) {
		for (int64 j = 1; j <= N; ++j) {
			if (i == j) arr[i][j] == 0;
			else arr[i][j] = INF;
		}
	}

	for (int64 i = 0; i < M; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = min(arr[a][b], c);
	}

	for (int64 l = 0; l < 100; ++l) {
		for (int64 i = 1; i <= N; ++i) {
			for (int64 j = 1; j <= N; ++j) {
				for (int64 k = 1; k <= N; ++k) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}

	for (int64 i = 1; i <= N; ++i) {
		for (int64 j = 1; j <= N; ++j) {
			if (arr[i][j] >= INF) cout << '0' << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}

	return EXIT_SUCCESS;
}