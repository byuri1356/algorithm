#include <iostream>
#include <vector>
using namespace std;
using int64 = int64_t;

int64 dp[1'000'001] = {0,1,2,4,};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int64 i = 4; i < 1'000'001; ++i) {
		dp[i] = (dp[i - 1] % 1'000'000'009) + (dp[i - 2] % 1'000'000'009) + (dp[i - 3] % 1'000'000'009);
		dp[i] %= 1'000'000'009;
	}

	int64 T, t;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		cout << dp[t]<<"\n";
		++i;
	}

	return EXIT_SUCCESS;
}