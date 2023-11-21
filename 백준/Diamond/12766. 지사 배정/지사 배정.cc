#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using vi = vector<int64>;
using vii = vector<pair<int, int>>;

int n, b, s, r; // 교차로 수 , 지사의 수 > 하위플젝 수,  도로의 수
int64 dp[5001][5001];
vi dist, rdist, nu;
vii adj[5001], radj[5001];

int64 sum(int l, int r) {
	return (nu[r] - nu[l - 1]) * (r - l);
}

void sol(int p, int l, int r, int pl, int pr) {
	if (l > r) return;

	int lem, m = (l + r) >> 1;
	int hi = min(m, pr);
	dp[p][m] = INT64_MAX;

	for (int i = pl; i <= hi; ++i) {
		int64 cur = dp[p - 1][i] + sum(i + 1, m);
		if (dp[p][m] > cur) {
			dp[p][m] = cur;
			lem = i;
		}
	}

	sol(p, l, m - 1, pl, lem);
	sol(p, m + 1, r, lem, pr);
}

void dijkstra(vii adj[], vi& dist) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, b + 1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();
		if (dist[cur] < cost) continue;

		for (auto& it : adj[cur]) {
			int ncost = it.second + cost;
			int ncur = it.first;

			if (ncost < dist[ncur]) {
				dist[ncur] = ncost;
				pq.push({ -ncost, ncur });
			}
		}

	}
}

int main() {

	fastio;

	cin >> n >> b >> s >> r;

	for (int i = 0; i < r; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		radj[b].push_back({ a, c });
	}

	dist.resize(n + 1, INT32_MAX);
	rdist.resize(n + 1, INT32_MAX);

	dijkstra(adj, dist);
	dijkstra(radj, rdist);

	nu.resize(b + 1);

	for (int i = 1; i <= b; ++i) {
		nu[i] = dist[i] + rdist[i];
	}

	sort(nu.begin(), nu.end());

	for (int i = 1; i <= b; ++i) {
		nu[i] += nu[i - 1];
		dp[1][i] = sum(1, i);
	}

	for (int i = 2; i <= s; ++i) {
		sol(i, 1, b, 1, b);
	}

	cout << dp[s][b];

	return EXIT_SUCCESS;
}