#include<iostream>

using namespace std;
using int64 = int64_t;

char arr[49][49];

int main() {
	int64 T, N;
	cin >> T;
	for (int64 t = 1; t <= T; ++t) {
		cin >> N;
		
		int64 ans = 0;
		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j < N; ++j) {
				cin >> arr[i][j];
			}
		}

		for (int64 i = 0; i < N / 2 ; ++i) {
			for (int64 j = N / 2 - i; j <= N / 2 + i; ++j) {
				ans = ans + (int)arr[i][j] - 48;
			}
		}

		for (int64 i = 0; i < N; ++i) {
			ans = ans + (int)arr[N / 2][i] - 48;
		}

		for (int64 i = N - 1, cnt = 0; i > N / 2; --i) {
			for (int64 j = N / 2 - cnt; j <= N / 2 + cnt; ++j) {
				ans = ans + (int)arr[i][j] - 48;
			}
			cnt++;
		}

		cout << '#' << t << ' ' << ans << "\n";
	}


	return EXIT_SUCCESS;
}