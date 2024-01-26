#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int N, pop[10001], dp[10001][2];
vector<int> adj[10001];

int sol(int idx, int status, int parent) {

	int& ref = dp[idx][status];

	if (ref != -1) return ref;

	ref = status ? pop[idx] : 0;

	for (int i = 0; i < adj[idx].size(); ++i) {
		int nIdx = adj[idx][i];
		if (nIdx == parent) continue;

		ref += status ? sol(nIdx, 0, idx) : max(sol(nIdx, 1, idx), sol(nIdx, 0, idx));
	}

	return ref;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> N;

	for (int i = 1; i <= N; ++i) cin >> pop[i];

	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << max(sol(1, 0, 0), sol(1, 1, 0));

	//cout << "!";

}