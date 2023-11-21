#include<iostream>
#include<algorithm>
using namespace std;
using int64 = int64_t;

int64 arr[1001], arr_inc[1001], arr_reinc[1001], ans=1;

int main() {
	int64 T;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> arr[i];
	}

	for (int64 i = 0; i < T-1; ++i) {
		for (int64 j = i + 1; j < T - 1; ++j) {
			if (arr[i] < arr[j]) {
				arr_inc[j] = max(arr_inc[i] + 1, arr_inc[j]);
			}
		}
	} 

	for (int64 i = T - 1; i > 0; --i) {
		for (int64 j = i - 1; j > 0; --j) {
			if (arr[i] < arr[j]) {
				arr_reinc[j] = max(arr_reinc[i] + 1, arr_reinc[j]);
			}
		}
	}

	for (int64 i = 0; i < T; ++i) {
		for (int64 j = i + 1; j < T; ++j) {
			if (arr[i] > arr[j]) ans = max(ans, (arr_inc[i] + arr_reinc[j] + 2));
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}