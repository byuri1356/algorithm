#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		bool isLoop = false;
		int N, M, W;
		int64 dist[501] = { 0, };
		vector<pair<int64, int64>> vec[501];
		
		cin >> N >> M >> W;
		for (int i = 0; i < M; ++i) {
			int st, ed, wt;
			cin >> st >> ed >> wt;

			vec[st].push_back({ ed, wt });
			vec[ed].push_back({ st, wt });
		}

		for (int i = 0; i < W; ++i) {
			int st, ed, wt;
			cin >> st >> ed >> wt;

			vec[st].push_back({ ed, -wt });
		}

		for (int i = 2; i <= N; ++i) {
			dist[i] = INF;
		}

		for (int i = 1; i < N; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (int k = 0; k < vec[j].size(); ++k) {
					int64 next_ed = vec[j][k].first;
					int64 next_wt = dist[j] + vec[j][k].second;

					if (next_wt < dist[next_ed]) {
						dist[next_ed] = next_wt;
					}
				}
			}
		}

		for (int i = 1; i < 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (int k = 0; k < vec[j].size(); ++k) {
					int64 next_ed = vec[j][k].first;
					int64 next_wt = dist[j] + vec[j][k].second;

					if (next_wt < dist[next_ed]) {
						isLoop = true;
					}
				}
			}
		}

		if (isLoop) cout << "YES" << "\n";
		else cout << "NO" << "\n";


	}

	return EXIT_SUCCESS;
}