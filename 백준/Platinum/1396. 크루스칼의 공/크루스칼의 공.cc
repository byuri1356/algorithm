#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

inline int find(vector<int>& parent, int a) {
	if (parent[a] != a) return find(parent, parent[a]);

	return a;
}

int main() {

	fastio;

	int N, M, Q;
	cin >> N >> M;

	vector<vector<int>> bs(M + 1);
	vector<tuple<int, int, int>> edge(M + 1);

	for (int i = 1; i <= M; ++i) {
		cin >> get<1>(edge[i]) >> get<2>(edge[i]) >> get<0>(edge[i]);
	}

	sort(edge.begin(), edge.end());

	cin >> Q;

	vector<pair<int, int>> query(Q), se(Q, { 1, M }), ans(Q);

	for (int i = 0; i < Q; ++i) {
		cin >> query[i].first >> query[i].second;
	}

	while (1) {
		bool tk = false;

		bs.clear();
		bs.resize(M + 1);

		for (int i = 0; i < Q; ++i) {
			if (se[i].first <= se[i].second) {
				tk = true;
				bs[(se[i].first + se[i].second) >> 1].push_back(i);
			}
		}

		if (!tk) break;

		vector<int> parent(N + 1), sz(N + 1, 1);

		for (int i = 1; i <= N; ++i) {
			parent[i] = i;
		}

		for (int i = 1; i <= M; ++i) {
			int a = find(parent, get<1>(edge[i]));
			int b = find(parent, get<2>(edge[i]));

			if (a != b) {
				if (a < b) {
					sz[a] += sz[parent[b]];
					parent[b] = a;
				}
				else {
					sz[b] += sz[parent[a]];
					parent[a] = b;
				}
			}

			for (auto it : bs[i]) {
				int a = find(parent, query[it].first);
				int b = find(parent, query[it].second);

				if (a != b) {
					se[it].first = i + 1;
				}
				else {
					ans[it].first = get<0>(edge[i]);
					ans[it].second = sz[a];

					se[it].second = i - 1;
				}
			}
		}
	}
	 
	for (int i = 0; i < Q; ++i) {
		if (se[i].first > M) cout << "-1" << "\n";
		else cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return EXIT_SUCCESS;
}