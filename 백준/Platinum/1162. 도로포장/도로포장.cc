#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

ll n, m, k, ans = INT64_MAX, dist[10'001][21];
vector<pll> adj[10'001];
priority_queue<tlll> pq;

void sol() {
	dist[1][0] = 0;
	pq.push({ 0, 0, 1 });
	while (!pq.empty()) {
		auto [cost, idx, cur] = pq.top();
		cost *= -1;
		pq.pop();

		if (dist[cur][idx] < cost) continue;

		for (auto i : adj[cur]) {
			auto& [nCur, nCost] = i;
			nCost += cost;
			if (nCost < dist[nCur][idx]) {
				dist[nCur][idx] = nCost;
				pq.push({ -nCost, idx, nCur });
			}
			if (idx < k && cost < dist[nCur][idx + 1]) {
				dist[nCur][idx + 1] = cost;
				pq.push({ -cost, idx + 1, nCur });
			}
		}
	}

	for (int i = 0; i <= k; ++i) ans = min(ans, dist[n][i]);
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	fill(&dist[0][0], &dist[10000][21], INT64_MAX);

	cin >> n >> m >> k;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	sol();

	cout << ans;

	return 0;
}