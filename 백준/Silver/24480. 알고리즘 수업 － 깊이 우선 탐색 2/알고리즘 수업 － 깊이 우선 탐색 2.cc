#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using int64 = int64_t;

vector<int64> vertex[200'001];
int64 visited[200'001] = {};
int64 Count=1;

inline void DFS(int64 R, int64 preR) {
	visited[R] = Count;
	//cout << preR << R << ' ' << Count << "\n";
	Count++;


	for (int i = 0; i < vertex[R].size();) {
		if (!visited[vertex[R][i]]) {
			DFS(vertex[R][i],R);
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
	//cout << "\n";

	for (int64 i = 1; i <= M; i++) {
		sort(vertex[i].begin(), vertex[i].end(), greater<int64>());
	}
	/*
	for (int64 i = 1; i <= M; i++) {
		for (int64 j = 0; j < vertex[i].size(); j++) {
			cout << vertex[i][j] <<' ';
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	DFS(R,R);

	for (int64 i = 1; i <= N;) {
		cout << visited[i] << "\n";
		++i;
	}

	return EXIT_SUCCESS;
}
