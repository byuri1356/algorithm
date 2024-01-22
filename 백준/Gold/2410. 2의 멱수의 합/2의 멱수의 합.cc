#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define MOD 1000000000
using namespace std;
using ll = long long;

ll dp[1'000'001];

int main() {

	fastio;

	int N; cin >> N;

	dp[0] = 1;

	for (int i = 0; (1 << i) <= N; ++i) {
		for (int j = (1 << i); j <= N; ++j) {
			dp[j] += dp[j - (1<<i)];
			dp[j] %= MOD;
		}
	}

	cout << dp[N];

}