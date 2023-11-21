#include<iostream>
#include<vector>
#include<tuple>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

const int64 MOD = 1e9 + 7;

void unn(vector<int>& parent, int lt, int rt) {
	if (lt < rt) parent[rt] = lt;
	else parent[lt] = rt;
}

int find(vector<int>& parent, int res) {
	if (res == parent[res]) return res;

	return find(parent, parent[res]);
}

int main() {

	fastio;

	int N, M;
	cin >> N >> M;

	vector<int> parent(N);
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
	}

	vector<tuple<int, int, int64>> adj(M);
	int64 sum = 1, ans = 0;
	for (int i = 0; i < M; ++i) {
		cin >> get<0>(adj[i]) >> get<1>(adj[i]);
		if (i) {
			sum *= 3;
			sum %= MOD;
		}
		get<2>(adj[i]) = sum;
	}

	for (int i = M - 1; i >= 0; --i) {
		int a = get<0>(adj[i]), b = get<1>(adj[i]), cost = get<2>(adj[i]);

		int lt = find(parent, a), rt = find(parent, b), st = find(parent, 0), ed = find(parent, N - 1);
		if ((lt == st && rt == ed) || (lt == ed && rt == st)) {
			ans += cost;
		}
		else if (lt != rt) unn(parent, lt, rt);

	}

	cout << ans % MOD;

	return EXIT_SUCCESS;
}