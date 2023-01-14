#include<iostream>

using namespace std;
using int64 = int64_t;

int64 arr[2001];

int main() {
	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 N, K;
		cin >> N >> K;

		for (int64 i = 0; i <= K; ++i) {
			arr[i] = 0;
		}

		for (int64 i = 0; i < N; ++i) {
			int64 A;
			cin >> A;

			if (A <= K) {
				for (int64 j = K - A; j > 0; --j) {
					if (arr[j]) arr[j + A] += arr[j];
				}
			}

			if (A <= K) arr[A]++;
			
		}
		cout << '#' << t << ' ' << arr[K] << "\n";

	}

	return EXIT_SUCCESS;
}