#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using int64 = int64_t;

vector<int64> vertex[200'001];
int64 visit[200'001] = {};
queue<int64> q;
int64 Count = 1;

inline void BFS(int64 R) {
	visit[R] = Count++;
	
	while (!q.empty()) {
		q.pop();
		for (int64 i = 0; i < vertex[R].size();) {
			if (!visit[vertex[R][i]]) {
				visit[vertex[R][i]] = Count;
				q.push(vertex[R][i]);
			}
			++i;
		}
		if (!q.empty()) {
			BFS(q.front());
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N, M, R;
	cin >> N >> M >> R;

	int64 u, v;
	for (int64 i = 1; i <= M;) {
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
		++i;
	}
	for (int64 i = 1; i <= N;) {
		sort(vertex[i].begin(), vertex[i].end(), greater<int64>());
		++i;
	}

	q.push(R);
	BFS(R);

	for (int64 i = 1; i <= N;) {
		cout << visit[i] << "\n";
		++i;
	}

	return EXIT_SUCCESS;
}