#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[6][20'001];
int64 v[6][20'001] = {};
vector<int64> adj[6][20'001];

inline bool Solve(int64 K, int64 V) {
	queue<int64> q;
	q.push(V);
	v[K][V] = 1;
	_visit[K][V] = true;
	while (!q.empty()) {
		int64 x = q.front();
		q.pop();
		for (int64 i = 0; i < adj[K][x].size(); ++i) {
			if (_visit[K][adj[K][x][i]]) {
				if (v[K][x] == v[K][adj[K][x][i]]) return false;
			}
			else {
				v[K][adj[K][x][i]] = -v[K][x];
				q.push(adj[K][x][i]);
				_visit[K][adj[K][x][i]] = true;
			}
		}
	}
	return true;
}

int main() {
	fastio;

	int64 K, V, E, a, b;
	cin >> K;
	for (int64 i = 0; i < K; ++i) {
		cin >> V >> E;
		for (int64 j = 0; j < E; ++j) {
			cin >> a >> b;
			adj[i][a].push_back(b);
			adj[i][b].push_back(a);
		}
		bool _token = true;
		for (int64 j = 1; j <= V; ++j) {
			if(_visit[i][j]) continue;
			if (!Solve(i, j)) {
				_token = false;
				break;
			}
		}
		if (_token) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return EXIT_SUCCESS;
}