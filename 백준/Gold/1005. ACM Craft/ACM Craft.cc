#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int T, N, K, W, pr[1001], dg[1001];
vector<int> cs;
vector<vector<int>> adj;
queue<int> que;

int main() {

	cin >> T;
	while (T--) {
		cin >> N >> K;
		adj.resize(N + 1);
		cs.resize(N + 1);
		for (int i = 1; i <= N; ++i) cin >> pr[i], cs[i] = pr[i];
		while (K--) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			++dg[b];
		}
		cin >> W;
		for (int i = 1; i <= N; ++i) if (!dg[i]) que.push(i);
		while (!que.empty()) {
			int cn = que.front();
			que.pop();
			for (auto& nn : adj[cn]) {
				--dg[nn];
				cs[nn] = max(cs[nn], cs[cn] + pr[nn]);
				if (!dg[nn]) que.push(nn);
			}
		}

		cout << cs[W] << "\n";

		adj.clear();
		cs.clear();
	}

	return 0;
}