#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int anc[200001][19], depth[200001];
int64 cost[200001][19], maxx;
vector<pair<int, int64>> adj[200001];

inline void LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		int dif = log2(depth[a] - depth[b]);

		maxx = max(maxx, cost[a][dif]);

		LCA(anc[a][dif], b);
		return;
	}
	else if (depth[a] < depth[b]) {
		int dif = log2(depth[b] - depth[a]);

		maxx = max(maxx, cost[b][dif]);

		LCA(a, anc[b][dif]);
		return;
	}
	else if (a != b) {
		for (int i = 1; i < 19; ++i) {
			if (anc[a][i] == anc[b][i]) {

				maxx = max(maxx, max(cost[a][i - 1], cost[b][i - 1]));

				LCA(anc[a][i - 1], anc[b][i - 1]);
				return;
			}
		}
	}

	return;
}

inline void DFS(int parent, int cur, int cst) {
	anc[cur][0] = parent;
	cost[cur][0] = cst;
	depth[cur] = depth[parent] + 1;

	for (int i = 1; i < 19; ++i) {
		anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
		cost[cur][i] = max(cost[anc[cur][i - 1]][i - 1], cost[cur][i - 1]);
	}

	for (auto& it : adj[cur]) {
		if (it.first != parent) {
			DFS(cur, it.first, it.second);
		}
	}
}

inline void un(vector<int>& parent, int a, int b) {
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

inline int getP(vector<int>& parent, int num) {
	if (parent[num] == num) return num;
	return getP(parent, parent[num]);
}

int main() {

	fastio;

	int N, M;
	int64 ans = 0;
	cin >> N >> M;

	vector<int> parent(N + 1);
	vector<tuple<int, int, int64>> arr;
	priority_queue<tuple<int64, int, int>> W;

	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}

	while (M--) {
		int a, b;
		int64 c;
		cin >> a >> b >> c;

		arr.push_back({ a, b, c });
		W.push({ -c, a, b });
	}

	while (!W.empty()) {
		int64 c = -get<0>(W.top());
		int a = get<1>(W.top());
		int b = get<2>(W.top());

		W.pop();

		int pa = getP(parent, a);
		int pb = getP(parent, b);

		if (pa != pb) {
			ans += c;
			un(parent, pa, pb);
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
	}

	DFS(1, 1, 0);

	for (auto& it : arr) {
		maxx = INT64_MIN;

		LCA(get<0>(it), get<1>(it));

		cout << ans - maxx + get<2>(it) << "\n";
	}

	return EXIT_SUCCESS;
}