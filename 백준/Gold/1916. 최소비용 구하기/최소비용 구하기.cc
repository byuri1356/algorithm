#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;

#define MAX 1002
#define INF 99999999
int64 dist[MAX];
vector<pair<int64, int64>> adj[MAX];
priority_queue<pair<int64, int64>>pq;
inline void dijkstra(int64 start) {
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int64 cost = -pq.top().first;
		int64 cur = pq.top().second;
		pq.pop();
				
		if (dist[cur] < cost) {
			continue;
		}
		for (int64 i = 0; i < adj[cur].size(); i++) {
			int64 next = adj[cur][i].first;
			int64 nCost = cost + adj[cur][i].second;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				pq.push({ -nCost, next });
			}
		}
	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	fill(dist, dist + MAX, INF);

	int64 V, E;

	cin >> V >> E;

	for (int64 i = 0; i < E; i++) {
		int64 from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
	}

	int64 _start, _end;
	cin >> _start >> _end;
	dijkstra(_start);
	cout << dist[_end];
	return EXIT_SUCCESS;
}