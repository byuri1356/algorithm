#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool bfs_visit[1'001];
int64 Ans;
vector<int64> v[1'001];
queue<int64> q;

inline void BFS(int64 V) {
	q.push(V);
	bfs_visit[V] = true;
	while (!q.empty()) {
		int64 x = q.front();
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

	int64 N, M, a, b;
	cin >> N >> M;

	for (int64 i = 0; i < M; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int64 i = 1; i <= N; ++i) {
		if (!bfs_visit[i]) {
			Ans++;
			BFS(i);
		}
	}
	
	cout << Ans;

	return EXIT_SUCCESS;
}