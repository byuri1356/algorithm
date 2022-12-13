#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using int64 = int64_t;

int64 _visit[11], ans = 1;
vector<int64> v[11];

void DFS(int64 x) {
	for (auto iter : v[x]) {
		if (!_visit[iter]) {
			_visit[iter] = _visit[x] + 1;
			ans = max(ans, _visit[iter]);
			DFS(iter);
			_visit[iter] = 0;
		}
	}
}

int main() {
	int64 T;
	cin >> T;
	
	for (int64 t = 1; t <= T; ++t) {
		int64 N, M;
		cin >> N >> M;

		for (int64 i = 0; i < M; ++i) {
			int64 x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		for (int64 i = 1; i <= N; ++i) {
			_visit[i] = 1;

			DFS(i);

			for (int64 j = 1; j <= N; ++j) {
				_visit[j] = 0;
			}
		}

		for (int i = 1; i <= N; ++i) {
			v[i].clear();
		}

		cout << '#' << t << ' ' << ans << "\n";
		ans = 1;
		

	}


	return EXIT_SUCCESS;
}