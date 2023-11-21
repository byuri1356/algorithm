#include<iostream>
#include<vector>
#include<cmath>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, Q, cnt;
vector<int> seg, order, pa, sz, top;
vector<pair<int, int>> edge, adj[200001];

int find(int st, int ed, int nd, int lt, int rt) {
	if (rt < st || ed < lt) return 1;
	if (lt <= st && ed <= rt) return seg[nd];

	int hf = (st + ed) / 2;

	return find(st, hf, nd * 2, lt, rt) & find(hf + 1, ed, nd * 2 + 1, lt, rt);
}

int update(int st, int ed, int nd, int tg, int pv) {
	if (tg < st || ed < tg) return seg[nd];
	if (tg <= st && ed <= tg) return seg[nd] = pv;

	int hf = (st + ed) / 2;

	return seg[nd] = update(st, hf, nd * 2, tg, pv) & update(hf + 1, ed, nd * 2 + 1, tg, pv);
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

	cin >> N >> Q;

	int h = (int)ceil(log2(N));
	int ts = 1 << h + 1;

	seg.resize(ts, 1);

	edge.resize(N), pa.resize(N + 1), sz.resize(N + 1, 1), order.resize(N + 1), top.resize(N + 1);
	pa[1] = 1, top[1] = 1;

	for (int i = 2; i <= N; ++i) {
		int a;
		cin >> a;

		adj[a].push_back({ i, 1 });
		adj[i].push_back({ a, 1 });
	}

	dfs();
	hld();

	while (Q--) {
		int a, oa, b, ob, c, ans = 1;
		cin >> oa >> ob >> c;
		a = oa, b = ob;

		while (top[a] ^ top[b]) {
			if (sz[top[a]] < sz[top[b]]) {
				swap(a, b);
			}
			ans = ans & find(1, N, 1, order[top[b]], order[b]);
			b = pa[top[b]];
		}

		if (order[a] < order[b]) {
			swap(a, b);
		}

		ans = ans & find(1, N, 1, order[b] + 1, order[a]);

		if (ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		if (c) {
			if (ans) {
				update(1, N, 1, order[oa], 0);
			}
			else {
				update(1, N, 1, order[ob], 0);
			}
		}
	}

	return EXIT_SUCCESS;
}
