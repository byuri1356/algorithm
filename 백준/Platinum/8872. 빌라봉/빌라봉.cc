#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using vvp = vector<vector<pair<int, int>>>;

typedef struct Node {
	int dp, one, two;
}Node;

int cost, mx, radius;
vvp adj;
vector<Node> nd;

inline void findCC(int parent, int cur) {

	cost = min(cost, max(nd[cur].one, nd[cur].two));
	radius = max(radius, nd[cur].one + nd[cur].two);

	for (auto& it : adj[cur]) {
		int nextD = it.first;
		int nextC = it.second;

		if (parent == nextD) continue;

		if (nd[nextD].dp + nd[nextD].one == mx) {
			nd[nextD].two = max(nd[cur].two + nextC, nd[nextD].two);

			findCC(cur, nextD);
		}

	}

}

inline void dfs(int cur) {
	nd[cur].one = 0;
	nd[cur].two = 0;

	for (auto& it : adj[cur]) {
		int nextD = it.first;
		int nextC = it.second;

		if (nd[nextD].dp == -1) {
			nd[nextD].dp = nd[cur].dp + nextC;

			dfs(nextD);
			int dis = nd[nextD].one + nextC;

			if (dis > nd[cur].one) {
				nd[cur].two = nd[cur].one;
				nd[cur].one = dis;
			}
			else if (dis > nd[cur].two) {
				nd[cur].two = dis;
			}

		}
	}
}

int main() {

	fastio;

	int N, M, L;
	cin >> N >> M >> L;

	vector<int> cc;
	nd.resize(N, { -1, -1, -1 });
	adj.resize(N);

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	for (int i = 0; i < N; ++i) {
		if (nd[i].dp == -1) {
			nd[i].dp = 0;
			dfs(i);

			mx = nd[i].one;
			cost = INT32_MAX;
			findCC(i, i);
			cc.push_back(cost);
		}
	}

	sort(cc.begin(), cc.end(), greater<int>());

	if (cc.size() == 1) {
		cout << radius;
	}
	else if (cc.size() == 2) {
		cout << max(radius, cc[0] + cc[1] + L);
	}
	else {
		cout << max(radius, max(cc[0] + cc[1] + L, cc[1] + cc[2] + 2 * L));
	}

	return EXIT_SUCCESS;
}