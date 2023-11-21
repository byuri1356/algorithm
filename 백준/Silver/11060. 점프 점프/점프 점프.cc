#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1001], dp[1001], Ans;
queue<int64> q;

int main() {
	fastio;

	int64 N;
	cin >> N;
	for (int64 i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	q.push(1);
	while (!q.empty()) {
		int64 x = q.front();
		q.pop();
		for (int64 i = 1; i <= arr[x]; ++i) {
			if (!dp[x + i] && x+i <= 1000) {
				dp[x + i] = dp[x] + 1;
				q.push(x + i);
			}
		}
	}
	
	if (dp[N]) cout << dp[N];
	else if (N == 1) cout << 0;
	else cout << -1;

	return EXIT_SUCCESS;
}