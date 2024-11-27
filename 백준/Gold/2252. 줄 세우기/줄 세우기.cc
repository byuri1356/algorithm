#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dg[32001];
vector<int> adj[32001];
queue<int> que;

void bfs(int a) {
	que.push(a);
	while (!que.empty()) {
		int cn = que.front();
		que.pop();
		cout << cn << " ";
		for (auto& nn : adj[cn]) {
			dg[nn]--;
			if (!dg[nn]) {
				que.push(nn);
				dg[nn] = -1;
			}
		}
	}
}

int main() {

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		dg[b]++;
	}

	for (int i = 1; i <= n; ++i) if (!dg[i]) bfs(i);

	return 0;
}