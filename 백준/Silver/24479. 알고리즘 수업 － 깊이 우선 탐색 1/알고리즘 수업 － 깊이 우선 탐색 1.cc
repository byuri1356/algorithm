#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using int64 = int64_t;

vector<int64> vertex[200'001];
int64 visited[200'001] = {};
int64 Count=1;

inline void DFS(int64 R) {
	visited[R] = Count;
	Count++;

	for (int i = 0; i < vertex[R].size();) {
		if (!visited[vertex[R][i]]) {
			DFS(vertex[R][i]);
		}
		++i;
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N, M, R;
	cin >> N >> M >> R;
	visited[R] = 1;

	int64 u, v;
	for (int64 i = 1; i <= M;) {
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
		++i;
	}

	for (int64 i = 1; i <= M; i++) {
		sort(vertex[i].begin(), vertex[i].end(), less<int64>());
	}

	DFS(R);

	for (int64 i = 1; i <= N;) {
		cout << visited[i] << "\n";
		++i;
	}

	return EXIT_SUCCESS;
}
