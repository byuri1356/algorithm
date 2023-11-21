#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 1e8
using namespace std;

int N;
int adj[16][16];
int dp[16][1 << 16];

inline int TSP(int cur, int stt) {
	if (stt == (1 << N) - 1) {
		return dp[cur][stt] = adj[cur][0];
	}

	if (dp[cur][stt] != -1) return dp[cur][stt];

	dp[cur][stt] = INF;

	for (int i = 1; i < N; ++i) {
		int cmp = 1 << i;
		if (!(stt & cmp)) {
			dp[cur][stt] = min(dp[cur][stt], TSP(i, stt|cmp) + adj[cur][i]);
		}
	}
	
	return dp[cur][stt];
}

int main() {

	fastio;

	fill_n(&dp[0][0], 16 * (1 << 16), -1);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> adj[i][j];
			if (adj[i][j] == 0 && i != j) {
				adj[i][j] = INF;
			}
		}
	}

	cout<<TSP(0, 1);

	return EXIT_SUCCESS;
}