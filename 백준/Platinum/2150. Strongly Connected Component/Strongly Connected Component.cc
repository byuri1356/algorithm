#include<iostream>
#include<vector>
#include<algorithm>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int v, e, o, sz, visited[10001], scc[10001];
vector<int> stack;
vector<int> adj[10001];
vector<vector<int>> ans;

bool cmp(vector<int>& v1, vector<int>& v2) {
	return v1[0] < v2[0];
}

int sol(int cur) {
	stack.push_back(cur);
	visited[cur] = ++o;
	int parent = o;

	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];
		if (!visited[next]) parent = min(parent, sol(next));
		else if (!scc[next]) parent = min(parent, visited[next]);
	}

	if (parent == visited[cur]) {
		vector<int> tmp;
		int here;
		do {
			here = stack.back();
			stack.pop_back();
			scc[here] = 1;
			tmp.push_back(here);
		} while (here != cur);

		sort(tmp.begin(), tmp.end());
		ans.push_back(tmp);
		sz++;
	}

	return parent;
}

int main() {

	fastio;

	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= v; ++i) {
		if (!visited[i]) sol(i);
	}

	sort(ans.begin(), ans.end(), cmp);
	cout << sz << "\n";
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << -1 << "\n";
	}

	return 0;
}