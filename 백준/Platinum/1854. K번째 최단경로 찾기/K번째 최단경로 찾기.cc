#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int n, m, k;
vector<pii> adj[1002];
priority_queue<int> d[1002];
priority_queue<pii> q;

void sol() {
	q.push({ 0, 1 });
	d[1].push(0);

	while (!q.empty()) {
		int cur = q.top().second;
		int cost = -q.top().first;
		q.pop();

		for (int i = 0; i < adj[cur].size(); ++i) {
			auto [curN, costN] = adj[cur][i];
			costN += cost;

			if (d[curN].size() < k) {
				d[curN].push(costN);
				q.push({ -costN, curN });
			}
			else if (costN < d[curN].top()) {
				d[curN].push(costN);
				q.push({ -costN, curN });
				d[curN].pop();
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	sol();

	for (int i = 1; i <= n; ++i) {
		if (d[i].size() < k) cout << -1 << "\n";
		else cout << d[i].top() << "\n";
	}

	return 0;
}