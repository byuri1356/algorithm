#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int main() {
	fastio;

	while (1) {
		int64 N, M;
		cin >> N >> M;
		if (!(N || M)) break;

		bool needCheck[500] = { false, };
		int64 dddist[500];
		int64 ddist[500];
		int64 dist[500];
		int64 S, D;
		vector<pair<int64, int64>> vin[500], vout[500];
		priority_queue<pair<int64, int64>> pq;

		cin >> S >> D;

		for (int64 i = 0; i < N; ++i) {
			dist[i] = INF;
		}
		dist[S] = 0;
		pq.push({ 0, S });

		for (int64 i = 0; i < M; ++i) {
			int64 a, b, c;
			cin >> a >> b >> c;

			vin[a].push_back({ c, b });
			vout[b].push_back({ c, a });
		}

		while (!pq.empty()) {
			int64 cur = pq.top().second;
			int64 dis = -pq.top().first;

			pq.pop();

			if (dist[cur] < dis) continue;

			for (auto& iter : vin[cur]) {
				int64 next_c = iter.second;
				int64 next_d = iter.first + dist[cur];

				if (dist[next_c] > next_d) {
					dist[next_c] = next_d;
					pq.push({ -next_d, next_c });
				}
			}
		}


		for (int64 i = 0; i < N; ++i) {
			ddist[i] = INF;
		}

		needCheck[D] = true;
		ddist[D] = 0;
		pq.push({ 0, D }); dist[0];

		while (!pq.empty()) {
			int64 cur = pq.top().second;
			int64 dis = -pq.top().first;

			pq.pop();

			if (ddist[cur] < dis) continue;

			for (auto& iter : vout[cur]) {
				int64 next_c = iter.second;
				int64 next_d = iter.first + ddist[cur];

				if ((dist[cur] == dist[next_c] + iter.first) && needCheck[cur]) {
					needCheck[next_c] = true;
				}

				if (ddist[next_c] > next_d) {
					ddist[next_c] = next_d;
					pq.push({ -next_d, next_c });
				}
			}
		}

		for (int64 i = 0; i < N; ++i) {
			dddist[i] = INF;
		}

		dddist[D] = 0;
		pq.push({ 0, D }); dist[0];

		while (!pq.empty()) {
			int64 cur = pq.top().second;
			int64 dis = -pq.top().first;

			pq.pop();

			if (dddist[cur] < dis) continue;

			for (auto& iter : vout[cur]) {
				int64 next_c = iter.second;
				int64 next_d = iter.first + dddist[cur];

				if ((dist[cur] == dist[next_c] + iter.first) && needCheck[cur]) {
					continue;
				}

				if (dddist[next_c] > next_d) {
					dddist[next_c] = next_d;
					pq.push({ -next_d, next_c });
				}
			}
		}

		if (dddist[S] == INF) cout << -1 << "\n";
		else cout << dddist[S] << "\n";
	}

	return EXIT_SUCCESS;
}