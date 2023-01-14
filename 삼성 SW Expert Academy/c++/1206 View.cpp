#include<iostream>
#include<algorithm>

using namespace std;
using int64 = int64_t;

int64 arr[1002], ans;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N;

	for (int64 i = 1; i <= 10; ++i) {
		cin >> N;
		for (int64 j = 0; j < N; ++j) {
			cin >> arr[j];
		}
		
	
		for (int64 j = 2; j < N - 2; ++j) {
			int64 max_height = 0;
			max_height = max(max_height, arr[j - 2]);
			max_height = max(max_height, arr[j - 1]);
			max_height = max(max_height, arr[j + 1]);
			max_height = max(max_height, arr[j + 2]);
			if (arr[j] > max_height) ans = ans + arr[j] - max_height;
		}

		cout << '#' << i << ' ' << ans << "\n";
		ans = 0;
	}


	return EXIT_SUCCESS;
}