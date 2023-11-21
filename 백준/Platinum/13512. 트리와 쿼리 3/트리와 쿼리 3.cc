#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M, cnt;
vector<int> seg, order, pa, sz, top, adj[100001], rb, od;

int fd(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 100001;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return min(fd(s, h, n * 2, l, r), fd(h + 1, e, n * 2 + 1, l, r));
}

int ud(int s, int e, int n, int p, int d) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) return seg[n] = d;

	int h = (s + e) >> 1;

	return seg[n] = min(ud(s, h, n * 2, p, d), ud(h + 1, e, n * 2 + 1, p, d));
}

void hld(int cur) {
	order[cur] = ++cnt;
	rb[cnt] = cur;

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

	cin >> N;

	int h = (int)ceil(log2(N));
	int ts = 1 << h + 1;

	seg.resize(ts, 100001);
	pa.resize(N + 1), sz.resize(N + 1, 1), order.resize(N + 1), top.resize(N + 1), rb.resize(N + 1), od.resize(N+1, 100001);
	pa[1] = 1, top[1] = 1;

	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	hld(1);

	cin >> M;
	while (M--) {
		int a, b, c = 100001;
		cin >> a >> b;
		switch (a) {
		case 1:
			od[order[b]] = od[order[b]] == 100001 ? order[b] : 100001;
			ud(1, N, 1, order[b], od[order[b]]);
			break;
		case 2:
			while (top[b] ^ 1) {
				c = min(c, fd(1, N, 1, order[top[b]], order[b]));
				b = pa[top[b]];
			}

			c = min(c, fd(1, N, 1, 1, order[b]));
			c = c == 100001 ? -1 : rb[c];
			cout << c << "\n";
			break;
		}
	}


	return EXIT_SUCCESS;
}