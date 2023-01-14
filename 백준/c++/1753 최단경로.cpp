#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 V, E, K, dist[20'001];

vector<pair<int64, int64>> vertex[20'001];
priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64 >>> pq;

inline void dijkstra(int64 K) {
    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty()) {
        int64 distance = pq.top().first;
        int64 cur = pq.top().second;
        pq.pop();

        if (dist[cur] < distance) continue;

        for (int64 i = 0; i < vertex[cur].size(); ++i) {
            int64 next_d = distance + vertex[cur][i].first;
            int64 next_v = vertex[cur][i].second;

            if (next_d < dist[next_v]) {
                dist[next_v] = next_d;
                pq.push({ next_d, next_v });
            }
        }
    }
}

int main() {
    fastio;

    int64 u, v, w;

    cin >> V >> E >> K;
    for (int64 i = 1; i <= V; ++i) {
        dist[i] = INF;
    }

    for (int64 i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        vertex[u].push_back({ w,v });
    }

    dijkstra(K);

    for (int64 i = 1; i <= V; ++i) {
        if (dist[i] == INF)  cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return EXIT_SUCCESS;
}