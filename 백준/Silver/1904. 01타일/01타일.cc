#include <iostream>
using namespace std;
using int64 = int64_t;

int64 dp[1'000'001];

inline void Solve(int64 T) {
	if (T >= 3) {
		for (int64 i = 3; i <= T;) {
			dp[i] = (dp[i - 1]%15746) + (dp[i - 2] % 15746);
			++i;
		}
	}
}

int main() {
	int64 T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	Solve(T);
	cout << dp[T] % 15746;

	return 0;
}