#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using int64 = int64_t;

int ar[10001];
int arr[10001] = { 10000, };
int dp[10001];

inline void Solve(int T) {
	for (int i = 4; i <= T;) {
		dp[i] = max(ar[i] + ar[i - 1] + dp[i - 3], dp[i - 1]);
		dp[i] = max(dp[i], ar[i] + dp[i - 2]);
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 1; i <= T;) {
		cin >> arr[i];
		ar[i] = arr[i];
		++i;
	}

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	sort(arr, arr + 4);
	dp[3] = arr[1] + arr[2];

	if (T >= 4) {
		Solve(T);
	}
	
	cout << dp[T];

	return EXIT_SUCCESS;
}