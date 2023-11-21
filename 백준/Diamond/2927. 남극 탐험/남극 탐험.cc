#include<iostream>
#include<vector>
#include<cmath>
#include<tuple>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M, cnt;
vector<int64> seg, order, pa, sz, top, adj[100001], pg, parent;
vector<tuple<string, int, int>> qry;

int64 fd(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return fd(s, h, n * 2, l, r) + fd(h + 1, e, n * 2 + 1, l, r);
}

int64 ud(int s, int e, int n, int p, int d) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) return seg[n] = d;

	int h = (s + e) >> 1;

	return seg[n] = ud(s, h, n * 2, p, d) + ud(h + 1, e, n * 2 + 1, p, d);
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

void un(int a, int b) {
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int a) {
	if (parent[a] == a) return a;
	return find(parent[a]);
}

int main() {

	fastio;

	cin >> N;

	int h = (int)ceil(log2(N));
	int ts = 1 << h + 1;

	seg.resize(ts);
	pa.resize(N + 1), sz.resize(N + 1, 1), order.resize(N + 1), top.resize(N + 1), pg.resize(N + 1), parent.resize(N + 1);
	pa[1] = 1, top[1] = 1;

	for (int i = 1; i <= N; ++i) cin >> pg[i], parent[i] = i;

	cin >> M;
	while (M--) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		qry.push_back({ s,a,b });

		if (s == "bridge") {
			int A = a, B = b;
			a = find(a);
			b = find(b);
			if (a != b) {
				un(a, b);
				adj[A].push_back(B);
				adj[B].push_back(A);
			}
		}
	}

	for (int i = 2; i <= N; ++i) {
		int a = find(1);
		int b = find(i);

		if (a != b) {
			un(a, b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	dfs(1);
	hld(1);

	for (int i = 1; i <= N; ++i) {
		ud(1, N, 1, order[i], pg[i]);
		parent[i] = i;
	}

	for (auto& it : qry) {
		string s = get<0>(it);
		int a = get<1>(it), b = get<2>(it);
		if (s == "bridge") {
			a = find(a);
			b = find(b);

			if (a != b) {
				un(a, b);
				cout << "yes" << "\n";
			}
			else cout << "no" << "\n";
		}
		else if (s == "penguins") {
			ud(1, N, 1, order[a], b);
		}
		else {
			int A = a, B = b, ans = 0;
			a = find(a);
			b = find(b);

			if (a != b) {
				cout << "impossible" << "\n";
			}
			else {
				while (top[A] ^ top[B]) {
					if (sz[top[B]] < sz[top[A]]) swap(A, B);
					ans += fd(1, N, 1, order[top[A]], order[A]);
					A = pa[top[A]];
				}

				if (order[B] < order[A]) swap(A, B);
				ans += fd(1, N, 1, order[A], order[B]);
				cout << ans << "\n";
			}
		}
		
	}

	return EXIT_SUCCESS;
}