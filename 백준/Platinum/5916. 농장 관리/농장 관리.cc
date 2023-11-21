#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M, cnt;
vector<int64> seg, lazy, order, pa, sz, top, adj[100001];

void udlazy(int s, int e, int n) {
	if (!lazy[n]) return;

	seg[n] += (e - s + 1) * lazy[n];

	if (s != e) {
		lazy[n * 2] += lazy[n];
		lazy[n * 2 + 1] += lazy[n];
	}

	lazy[n] = 0;
}

int64 fd(int s, int e, int n, int l, int r) {
	udlazy(s, e, n);

	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return fd(s, h, n * 2, l, r) + fd(h + 1, e, n * 2 + 1, l, r);
}

int64 ud(int s, int e, int n, int l, int r, int d) {
	udlazy(s, e, n);

	if (r < s || e < l) return seg[n];
	if (l <= s && e <= r) {
		seg[n] += (e - s + 1) * d;

		if (s != e) {
			lazy[n * 2] += d;
			lazy[n * 2 + 1] += d;
		}

		return seg[n];
	}

	int h = (s + e) >> 1;
	return seg[n] = ud(s, h, n * 2, l, r, d) + ud(h + 1, e, n * 2 + 1, l, r, d);
}

void hld(int cur) {
	order[cur] = ++cnt;

	for (auto& n : adj[cur]) {
		if (n ^ pa[cur]) {
			top[n] = n == adj[cur][0] ? top[cur] : n;

			hld(n);
		}
	}
}

int dfs(int cur) {
	for (auto& n : adj[cur]) {
		if (n ^ pa[cur]) {
			pa[n] = cur;
			sz[cur] += dfs(n);

			if (sz[adj[cur][0]] < sz[n]) swap(adj[cur][0], n);
		}
	}

	return sz[cur];
}

int main() {

	fastio;

	cin >> N >> M;

	int h = (int)ceil(log2(N));
	int ts = 1 << h + 1;

	seg.resize(ts), lazy.resize(ts);
	pa.resize(N + 1), sz.resize(N + 1, 1), order.resize(N + 1), top.resize(N + 1);
	pa[1] = 1, top[1] = 1;

	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	hld(1);

	while (M--) {
		char q;
		int64 a, b, ans = 0;
		cin >> q >> a >> b;

		switch (q) {
		case 'P':
			while (top[a] ^ top[b]) {
				if (sz[top[b]] < sz[top[a]]) swap(a, b);

				ud(1, N, 1, order[top[a]], order[a], 1);
				a = pa[top[a]];
			}

			if (order[b] < order[a]) swap(a, b);
			ud(1, N, 1, order[a] + 1, order[b], 1);

			break;
		case 'Q':
			while (top[a] ^ top[b]) {
				if (sz[top[b]] < sz[top[a]]) swap(a, b);

				ans += fd(1, N, 1, order[top[a]], order[a]);
				a = pa[top[a]];
			}

			if (order[b] < order[a]) swap(a, b);
			ans += fd(1, N, 1, order[a] + 1, order[b]);

			cout << ans << "\n";
			break;
		}
	}


	return EXIT_SUCCESS;
}