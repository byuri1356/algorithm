#include<iostream>
#include<string>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

const int MOD = 987654321;

ll N, dp[10001];

int main() {

	fastio;

	cin >> N;

	dp[0] = dp[2] = 1;

	for (int i = 4; i <= N; i += 2) {
		for (int j = 0; 0 <= i - j - 2; j += 2) {
			dp[i] =  (dp[i] + dp[i - j - 2] * dp[j]) % MOD;
		}
	}

	cout << dp[N];

}