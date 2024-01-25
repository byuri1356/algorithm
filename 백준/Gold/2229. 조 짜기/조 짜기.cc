#include<iostream>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int N, stu[1001], dp[1001];

int main() {

	fastio;

	cin >> N;

	for (int i = 1; i <= N; ++i) cin >> stu[i];

	for (int i = 1; i <= N; ++i) {
		int mx = stu[i], mi = stu[i];
		for (int j = i; 0 < j; --j) {
			mx = max(mx, stu[j]);
			mi = min(mi, stu[j]);
			dp[i] = max(dp[i], dp[j - 1] + mx - mi);
		}
	}

	cout << dp[N];
}