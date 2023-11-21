#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

vector<int64> v;
queue<int64> q;
int64 dp[100'001];

int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 1; i * i <= 100'000; ++i) {
		dp[i * i] = 1;
		q.push(i * i);
		v.push_back(i * i);
	}
	while (!dp[T]) {
		int64 x = q.front();
		q.pop();
		for (auto _iter : v) {
			if ((x + _iter) <= 100'000) {
				if (!dp[x + _iter]) {
					dp[x + _iter] = dp[x] + 1;
					q.push(x + _iter);
				}
				else if (dp[x + _iter] > dp[x] + 1) {
					dp[x + _iter] = dp[x] + 1;
					q.push(x + _iter);
				}
			}
		}
	}
	cout << dp[T];
	return EXIT_SUCCESS;
}