#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using vec = vector<int>;
using vv = vector<vector<int>>;
using vp = vector<pair<int, int>>;
using pqp = priority_queue<pair<int, int>>;

vec dist, pa;
vp adj[100001];
pqp pq;

int fd(int a) {
	if (a == pa[a]) return a;
	return fd(pa[a]);
}

void mg(int a, int b) {
	if (a < b) pa[b] = a;
	else pa[a] = b;
}

void dijkstra() {
	while (!pq.empty()) {
		int cr = pq.top().second;
		int cd = -pq.top().first;

		pq.pop();
		if (dist[cr] < cd) continue;

		for (auto& it : adj[cr]) {
			int nx = it.first;
			int nd = it.second + cd;

			if (nd < dist[nx]) {
				dist[nx] = nd;
				pq.push({ -nd, nx });
			}
		}
	}
}

int main() {

	fastio;

	int N, M, K, Q;
	cin >> N >> M >> K >> Q;

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a,c });
	}

	dist.resize(N + 1, INT32_MAX / 2);
	pa.resize(N + 1);

	for (int i = 0; i < K; ++i) {
		int a;
		cin >> a;
		pq.push({ 0, a });
		dist[a] = 0;
	}

	dijkstra();

	vec kd;

	for (int i = 1; i <= N; ++i) {
		kd.push_back(dist[i]);
	}

	sort(kd.begin(), kd.end());
	kd.erase(unique(kd.begin(), kd.end()), kd.end());

	int sz = kd.size();

	vec ans(Q);
	vp query(Q), bs(Q, { 1, sz });

	for (int i = 0; i < Q; ++i) {
		cin >> query[i].first >> query[i].second;
	}

	vv vx(sz);
	for (int i = 1; i <= N; ++i) {
		int idx = lower_bound(kd.begin(), kd.end(), dist[i]) - kd.begin();
		vx[idx].push_back(i);
	}

	while (true) {
		vv pbs(sz);
		bool tk = true;

		for (int i = 1; i <= N; ++i) {
			pa[i] = i;
		}

		for (int i = 0; i < Q; ++i) {
			int s = bs[i].first;
			int e = bs[i].second;

			if (s <= e) {
				int m = (s + e) >> 1;
				pbs[m].push_back(i);
				tk = false;
			}
		}

		if (tk) break;

		for (int i = sz - 1; i >= 0; --i) {
			for (auto& a : vx[i]) {
				for (auto& b : adj[a]) {
					int A = a;
					int B = b.first;

					A = fd(A);
					B = fd(B);

					if (A != B && dist[A] >= kd[i] && dist[B] >= kd[i]) {
						mg(A, B);
					}
				}
			}

			for (auto& it : pbs[i]) {
				int a = fd(query[it].first);
				int b = fd(query[it].second);

				if (a == b) {
					ans[it] = kd[i];
					bs[it].first = i + 1;
				}
				else {
					bs[it].second = i - 1;
				}
			}
		}
	}

	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}

	return EXIT_SUCCESS;
}