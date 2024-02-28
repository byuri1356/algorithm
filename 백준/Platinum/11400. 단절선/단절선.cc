#include<iostream>
#include<vector>
#include<set>
using namespace std;
using pii = pair<int, int>;

int vtx, edge, idx, vst[100001];
vector<int> adj[100001];
set<pii> ans;

int dfs(int cur, int par) {
	vst[cur] = ++idx;
	int res = vst[cur];

	for (auto& next : adj[cur]) {
		
		if (vst[next]) {
			if (par != next) res = min(res, vst[next]); 
		}
		else {
			int mi = dfs(next, cur);

			if (vst[cur] < mi) {
				int a = cur, b = next;
				if (b < a) swap(a, b);
				ans.insert({ a, b });
			}

			res = min(res, mi);
		}
	}

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

	dfs(1, 0);

	cout << ans.size() << "\n";
	for (auto& [a, b] : ans) cout << a << " " << b << "\n";

	return 0;
}