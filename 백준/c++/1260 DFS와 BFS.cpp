#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool dfs_visit[1'001], bfs_visit[1'001];
vector<int64> v[1'001];
queue<int64> q;

inline void DFS(int64 V) {
	cout << V << ' ';
	dfs_visit[V] = true;
	for (int64 i = 0; i < v[V].size(); ++i) {
		if (!dfs_visit[v[V][i]]) DFS(v[V][i]);
	}
}

inline void BFS(int64 V) {
	q.push(V);
	bfs_visit[V] = true;
	while (!q.empty()) {
		int64 x = q.front();
		cout << x << ' ';
		q.pop();
		for (int64 i = 0; i < v[x].size(); ++i) {
			if (!bfs_visit[v[x][i]]) {
				bfs_visit[v[x][i]] = true;
				q.push(v[x][i]);
			}
		}
	}
}

int main() {
	fastio;

	int64 N, M, V, a, b;
	cin >> N >> M >> V;

	for (int64 i = 0; i < M; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		sort(v[a].begin(), v[a].end());
		sort(v[b].begin(), v[b].end());
	}

	DFS(V); cout << "\n";
	BFS(V);

	return EXIT_SUCCESS;
}