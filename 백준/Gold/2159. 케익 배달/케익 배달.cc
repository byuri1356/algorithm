#include<iostream>
#include<algorithm>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

ll N, x, y, pos[100001][2], dp[100001][5];
ll dx[5] = { -1, 0, 1, 0, 0 }, dy[5] = { 0, 1, 0, -1, 0 };

ll sol(int idx, int dir, int curX, int curY) {

	ll& ref = dp[idx][dir];

	if (ref != -1) return ref;

	if (idx == N) return 0;

	ref = INT64_MAX;

	for (int i = 0; i < 5; ++i) {
		ll nxtX = pos[idx][0] + dx[i];
		ll nxtY = pos[idx][1] + dy[i];
		ref = min(ref, abs(curX - nxtX) + abs(curY - nxtY) + sol(idx + 1, i, nxtX, nxtY));
	}

	return ref;

}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> N >> x >> y;

	for (int i = 0; i < N; ++i) cin >> pos[i][0] >> pos[i][1];

	cout << min({ sol(0, 0, x, y), sol(0, 1, x, y), sol(0, 2, x, y), sol(0, 3, x, y), sol(0, 4, x, y) });

	//cout << "!";
}