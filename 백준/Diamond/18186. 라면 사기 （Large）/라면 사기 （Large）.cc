#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int64 N, B, C, ans = 0;
	cin >> N >> B >> C;
	vector<int64> arr(N + 2);

	if (B <= C) C = B;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; ++i) {
		if (arr[i + 1] > arr[i + 2]) {
			int res = min(arr[i], arr[i + 1] - arr[i + 2]);
			ans += res * (B + C);
			arr[i] -= res, arr[i + 1] -= res;

			res = min(arr[i], arr[i + 2]);
			ans += res * (B + 2 * C);
			arr[i] -= res, arr[i + 1] -= res, arr[i + 2] -= res;
		}
		else {
			int res = min(arr[i], arr[i + 1]);
			ans += res * (B + 2 * C);
			arr[i] -= res, arr[i + 1] -= res, arr[i + 2] -= res;

		}

		ans += arr[i] * B;
	}

	cout << ans;

	return EXIT_SUCCESS;
}