#include<iostream>
#include<vector>

using namespace std;

int N, M, dp[1001];
vector<int> adj[1001];

int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> N >> M;
	fill(dp, dp + N + 1, 1);
	while (M--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i) {
		for (auto& nn : adj[i]) {
			dp[nn] = dp[nn] < dp[i] + 1 ? dp[i] + 1 : dp[nn];
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << dp[i] << " ";
	}

	return 0;
}