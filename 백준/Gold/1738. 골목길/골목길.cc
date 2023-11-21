#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool tk;
int64 dist[101];
int64 _prev[101];
vector<pair<int, int64>> vec[101];
vector<int64> ans;

int main() {
	fastio;

	int N, M;
	cin >> N >> M;

	for (int i = 2; i <= N; ++i) {
		dist[i] = -INF;
	}

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (dist[j] == -INF) continue;
			for (int k = 0; k < vec[j].size(); ++k) {
				int next_N = vec[j][k].first;
				int64 next_D = vec[j][k].second + dist[j];

				if (dist[next_N] < next_D) {
					dist[next_N] = next_D;
					_prev[next_N] = j;
				}
			}
		}
	}

	if (dist[N] == -INF) cout << "-1";
	else {
		int64 res = dist[N];
		for (int i = 1; i <=N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (dist[j] == -INF) continue;
				for (int k = 0; k < vec[j].size(); ++k) {
					int next_N = vec[j][k].first;
					int64 next_D = vec[j][k].second + dist[j];

					if (dist[next_N] < next_D) {
						dist[next_N] = INF;
						_prev[next_N] = j;
					}
				}
			}
		}
		if (res != dist[N]) {
			cout << "-1";
			tk = true;
		}

		if (!tk) {
			int dummy_N = N;
			int cur_N = dummy_N;
			ans.push_back(dummy_N);
			 
			while (dummy_N != 1) {
				ans.push_back(_prev[dummy_N]);
				dummy_N = _prev[dummy_N];
			}

			for (int i = ans.size() - 1; i >= 0; --i) {
				cout << ans[i] << ' ';
			}
		}

	}

	return EXIT_SUCCESS;
}