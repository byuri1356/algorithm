#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
using int64 = int64_t;

int64 arr[11][11] = { {0,},{0,1,} };

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, N;
	cin >> T;

	for (int64 i = 1; i <= T; ++i) {
		cin >> N;
		for (int64 j = 2; j <= N; ++j) {
			for (int64 k = 1; k <= j; ++k) {
				arr[j][k] = arr[j - 1][k - 1] + arr[j - 1][k];
			}
		}

		cout << '#' << i << "\n";
		for (int64 j = 1; j <= N; ++j) {
			for (int64 k = 1; k <= j; ++k) {
				cout<<arr[j][k]<<' ';
			}
			cout << "\n";
		}
	}

	return EXIT_SUCCESS;
}