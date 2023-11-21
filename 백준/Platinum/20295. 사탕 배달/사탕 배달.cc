#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int anc[100001][18];
int can[100001][18];
int candy[100001];
int depth[100001];
bool isTrue[6];
vector<int> adj[100001];

inline pair<int, int> LCA(int a, int b, int sum) {
	if (depth[a] > depth[b]) {
		int dep = (int)log(depth[a] - depth[b]);
		return LCA(anc[a][dep], b, sum | can[a][dep]);
	}
	else if (depth[b] > depth[a]) {
		int dep = (int)log(depth[b] - depth[a]);
		return LCA(a, anc[b][dep], sum | can[b][dep]);
	}
	else if (a != b) {
		for (int i = 1; i < 18; ++i) {
			if (anc[a][i] == anc[b][i]) {
				return LCA(anc[a][i - 1], anc[b][i - 1], sum | can[a][i - 1] | can[b][i - 1]);
			}
		}
	}

	return { a, sum };
}

inline void initTree(int p, int c) {
	anc[c][0] = p;
	can[c][0] = candy[c] | candy[p];
	depth[c] = depth[p] + 1;

	for (int i = 1; i < 18; ++i) {
		anc[c][i] = anc[anc[c][i - 1]][i - 1];
		can[c][i] = can[c][i - 1] | can[anc[c][i - 1]][i - 1];
	}

	for (auto& iter : adj[c]) {
		if (iter != p) initTree(c, iter);
	}
}

int main() {

	fastio;

	int N, M;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> candy[i];
		isTrue[candy[i]] = true;
		candy[i] = 1 << candy[i];
	}

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	initTree(1, 1);

	cin >> M;

	int a, b, c;
	cin >> a >> b;
	if (isTrue[b]) {
		cout << "PLAY"<<"\n";
	}
	else {
		cout << "CRY"<<"\n";
	}
	c = a;

	for (int i = 1; i < M; ++i) {
		cin >> a >> b;
		pair<int, int> p = LCA(a, c, candy[a] | candy[c]);

		if ((p.second & 1 << b) == 1 << b)cout << "PLAY" << "\n";
		else cout << "CRY" << "\n";

		c = a;
	}

	return EXIT_SUCCESS;
}