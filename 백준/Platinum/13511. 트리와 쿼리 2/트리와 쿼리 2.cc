#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int dep[100001];
int arr[100001][17];
int64 dis[100001];
vector<pair<int, int64>> adj[100001];

inline int findPath(int a, int d) {
	if (!d) return a;

	for (int64 i = 1; i < 17; ++i) {
		if ((1 << i) > d) return findPath(arr[a][i - 1], d - (1 << (i - 1)));
	}
}

inline int LCA(int a, int b) {
	if (dep[a] > dep[b]) {
		return LCA(arr[a][(int)log2(dep[a] - dep[b])], b);
	}
	else if (dep[b] > dep[a]) {
		return LCA(a, arr[b][(int)log2(dep[b] - dep[a])]);
	}
	else if (a != b) {
		for (int i = 1; i < 17; ++i) {
			if (arr[a][i] == arr[b][i]) {
				return LCA(arr[a][i - 1], arr[b][i - 1]);
			}
		}
	}

	return a;
}

inline void initTree(int p, int c) {
	arr[c][0] = p;
	dep[c] = dep[p] + 1;

	for (int i = 1; i < 17; ++i) {
		arr[c][i] = arr[arr[c][i - 1]][i - 1];
	}

	for (auto& iter : adj[c]) {
		if (iter.first != p) {
			dis[iter.first] = dis[c] + iter.second;
			initTree(c, iter.first);
		}
	}
}

int main() {

	fastio;

	int N, M;
	cin >> N;

	for (int i = 0; i < N - 1; ++i) {

		int64 a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	initTree(1, 1);

	cin >> M;
	for (int i = 0; i < M; ++i) {

		int a, b, c, d;
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
			cout << dis[b] + dis[c] - 2 * dis[LCA(b, c)] << "\n";
		}
		else {
			cin >> b >> c >> d;
			int lca = LCA(b, c);
			int D = dep[b] + dep[c] - 2 * dep[lca] + 1 - d;
			if (d <= dep[b] - dep[lca] + 1) {
				cout << findPath(b, d - 1) << "\n";
			}
			else {
				cout << findPath(c, D) << "\n";
			}
		}

	}

	return EXIT_SUCCESS;
}