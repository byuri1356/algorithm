#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 dis[1'001], re_dis[1'001];
vector < pair<int64, int64>> vec[1'001], re_vec[1'001];
priority_queue<pair<int64, int64>> pq;

inline void re_dijkstra(int64 start) {
	re_dis[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int64 cur = pq.top().first;
		int64 distance = -pq.top().second;
		pq.pop();

		if (re_dis[cur] < distance) continue;

		for (int64 i = 0; i < re_vec[cur].size(); ++i) {
			int64 next_c = re_vec[cur][i].first;
			int64 next_d = re_vec[cur][i].second;

			if (distance + next_d < re_dis[next_c]) {
				re_dis[next_c] = distance + next_d;
				pq.push({ next_c, -re_dis[next_c] });
			}
		}
	}
}

inline void dijkstra(int64 start) {
	dis[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int64 cur = pq.top().first;
		int64 distance = -pq.top().second;
		pq.pop();

		if (dis[cur] < distance) continue;

		for (int64 i = 0; i < vec[cur].size(); ++i) {
			int64 next_c = vec[cur][i].first;
			int64 next_d = vec[cur][i].second;

			if (distance + next_d < dis[next_c]) {
				dis[next_c] = distance + next_d;
				pq.push({ next_c, -dis[next_c] });
			}
		}
	}
}

int main() {
	fastio;

	int64 N, M, X;
	cin >> N >> M >> X;

	for (int64 i = 1; i <= N; ++i) {
		dis[i] = INF;
		re_dis[i] = INF;
	}

	for (int64 i = 0; i < M; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;
		
		vec[a].push_back({ b,c });
		re_vec[b].push_back({ a,c });
	}

	dijkstra(X);
	re_dijkstra(X);

	int64 ans = 0;
	for (int64 i = 1; i <= N; ++i) {
		ans = max(ans, dis[i] + re_dis[i]);
	}

	cout << ans;

	return EXIT_SUCCESS;
}