#include<iostream>
#include<algorithm>
using namespace std;
using int64 = int64_t;

int64 arr[10001];

int main() {
	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 N, L;
		cin >> N >> L;

		for (int64 i = 0; i < N; ++i) {
			int64 S, K;
			cin >> S >> K;

			for (int64 j = L - K; j >= 0; --j) {
				arr[j + K] = max(arr[j] + S, arr[j + K]);
			}
		}

		cout << '#' << t << ' ' << arr[L] << "\n";
		for (int64 i = 0; i < 10001; ++i) {
			arr[i] = 0;
		}

	}


	return EXIT_SUCCESS;
}