#include<iostream>
#include<vector>
#include<cmath>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, cnt;
vector<int> seg, order, pa, sz, top;
vector<pair<int, int>> edge, adj[100001];

int find(int st, int ed, int nd, int lt, int rt) {
	if (rt < st || ed < lt) return 0;
	if (lt <= st && ed <= rt) return seg[nd];

	int hf = (st + ed) / 2;

	return max(find(st, hf, nd * 2, lt, rt), find(hf + 1, ed, nd * 2 + 1, lt, rt));
}

int update(int st, int ed, int nd, int tg, int pv) {
	if (tg < st || ed < tg) return seg[nd];
	if (tg <= st && ed <= tg) return seg[nd] = pv;

	int hf = (st + ed) / 2;

	return seg[nd] = max(update(st, hf, nd * 2, tg, pv), update(hf + 1, ed, nd * 2 + 1, tg, pv));
}

void hld(int cur = 1) {
	order[cur] = ++cnt;

	for (auto& nxt : adj[cur]) {
		if (pa[cur] ^ nxt.first) {
			top[nxt.first] = nxt == adj[cur][0] ? top[cur] : nxt.first;

			hld(nxt.first);

			update(1, N, 1, order[nxt.first], nxt.second);
		}
	}
}

int dfs(int cur = 1) {
	for (auto& nxt : adj[cur]) {
		if (pa[cur] ^ nxt.first) {
			pa[nxt.first] = cur;
			sz[cur] += dfs(nxt.first);

			if (sz[adj[cur][0].first] < sz[nxt.first] || adj[cur][0].first == pa[cur]) {
				swap(adj[cur][0], nxt);
			}
		}
	}

	return sz[cur];
}

int main() {

	fastio;

	cin >> N;

	int h = (int)ceil(log2(N));
	int ts = 1 << h + 1;

	seg.resize(ts);

	edge.resize(N), pa.resize(N + 1), sz.resize(N + 1, 1), order.resize(N + 1), top.resize(N + 1);
	pa[1] = 1, top[1] = 1;

	for (int i = 1; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });

		edge[i] = { a,b };
	}

	dfs();
	hld();

	int M;
	cin >> M;

	while (M--) {
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			if (order[edge[b].first] < order[edge[b].second]) {
				swap(edge[b].first, edge[b].second);
			}
			update(1, N, 1, order[edge[b].first], c);
			break;
		case 2:
			while (top[b] ^ top[c]) {
				if (sz[top[b]] < sz[top[c]]) {
					swap(b, c);
				}
				ans = max(ans, find(1, N, 1, order[top[c]], order[c]));
				c = pa[top[c]];
			}

			if (order[b] < order[c]) {
				swap(b, c);
			}

			ans = max(ans, find(1, N, 1, order[c] + 1, order[b]));

			cout << ans << "\n";
			break;
		}
	}

	return EXIT_SUCCESS;
}
