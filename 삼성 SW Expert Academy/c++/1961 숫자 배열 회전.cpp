#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[4][7][7];

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 N;
		cin >> N;

		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j < N; ++j) {
				cin >> arr[0][i][j];
			}
		}

		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j<N; ++j) {
				arr[1][i][j] = arr[0][N - 1 - j][i];
				arr[2][i][j] = arr[0][N - 1 - i][N - 1 - j];
				arr[3][i][j] = arr[0][j][N - 1 - i];
			}
		}

		cout << "#" << t << "\n";
		for (int64 i = 0; i < N; ++i) {
			for (int64 k = 1; k < 4; ++k) {
				for (int64 j = 0; j < N; ++j) {
					cout << arr[k][i][j];
				}
				cout << ' ';
			}
			cout << "\n";
		}
	}

	return EXIT_SUCCESS;
}