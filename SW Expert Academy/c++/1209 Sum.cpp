#include<iostream>
#include<algorithm>
using namespace std;
using int64 = int64_t;

int64 arr[100][100];
int64 sum, ans;

int main() {

	for (int64 t = 1; t <= 10; ++t) {
		int64 T;
		cin >> T;
		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				cin >> arr[i][j];
			}
		}

		sum = 0;
		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				sum += arr[i][j];
			}
			ans = max(ans, sum);
			sum = 0;
		}

		sum = 0;
		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				sum += arr[j][i];
			}
			ans = max(ans, sum);
			sum = 0;
		}

		sum = 0;
		for (int64 i = 0; i < 100; ++i) {
			sum += arr[0 + i][0 + i];
		}
		ans = max(ans, sum);
		sum = 0;

		sum = 0;
		for (int64 i = 0; i < 100; ++i) {
			sum += arr[0 + i][99 - i];
		}
		ans = max(ans, sum);
		sum = 0;

		cout << '#' << t << ' ' << ans << "\n";
		ans = 0;
	}

	return EXIT_SUCCESS;
}