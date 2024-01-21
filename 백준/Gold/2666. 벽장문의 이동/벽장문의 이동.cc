#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define MOD 1000000000
using namespace std;
using ll = long long;

int N, M, doorA, doorB, doorArr[21], dp[21][21];

int sol(int evt, int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];

	if (evt == M) return 0;

	int locA = a == 0 ? doorA : doorArr[a];
	int locB = b == 0 ? doorB : doorArr[b];

	return dp[a][b] = min(abs(doorArr[evt + 1] - locA) + sol(evt + 1, evt + 1, b), abs(doorArr[evt + 1] - locB) + sol(evt + 1, a, evt + 1));

}

int main() {

	fastio;

	cin >> N >> doorA >> doorB >> M;

	for (int i = 1; i <= M; ++i) cin >> doorArr[i];

	memset(dp, -1, sizeof dp);

	cout << sol(0, 0, 0);
	
	//cout << "!";
}