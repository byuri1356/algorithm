#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define MOD 1000000000
using namespace std;
using ll = long long;

int N, M, K, ans, dp[301][301];
vector<vector<pair<int, int>>> adj;

int sol(int n, int m) {
	if (M < m) return -1e8;

	if (n == N) return 0;

	if (dp[n][m] != -1) return dp[n][m];

	dp[n][m] = -1e8;

	for (int i = 0; i < adj[n].size(); ++i) {
		if(n < adj[n][i].first ) dp[n][m] = max(dp[n][m], sol(adj[n][i].first, m + 1) + adj[n][i].second);
	}
	
	return dp[n][m];
}

int main() {

	fastio;

	cin >> N >> M >> K;

	memset(dp, -1, sizeof dp);

	adj.resize(N+1);

	while (K--) {
		int a, b, c; cin >> a >> b >> c;

		adj[a].push_back({ b, c });
	}

	cout << sol(1, 1);

	//cout << "!";

}