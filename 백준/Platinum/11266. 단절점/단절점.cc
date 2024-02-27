#include<iostream>
#include<vector>
#include<set>
using namespace std;

int vtx, edge, idx, order[10001];
vector<int> adj[10001];
set<int> cv;

int dfs(int cur, bool root) {
	order[cur] = ++idx;
	int res = order[cur];
	int degree = 0;

	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];

		if (order[next]) {
			res = min(res, order[next]);
			continue;
		}

		degree++;
		int mi = dfs(next, 0);

		if ((!root && order[cur] <= mi)) cv.insert(cur);
		res = min(res, mi);
	}

	if (root && 1 < degree) cv.insert(cur);
	return res;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> vtx >> edge;
	while (edge--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= vtx; ++i) if (!order[i]) dfs(i, 1);

	cout << cv.size() << "\n";
	for (auto& i : cv) {
		cout << i << " ";
	}

	return 0;
}