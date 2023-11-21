#include<iostream>
#include<memory.h>
#include<cmath>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int N, W;
int dp[1001][1001]; // 경찰차 이동 거리
pair<int, int> A[1001]; // 경찰차 현재 위치
pair<int, int> B[1001];
int e[1001]; // 경찰차가 맡은 사건

inline void mem(int a, int b, int c) {
	if (c == W) return;

	if (abs(A[a].first - A[c + 1].first) + abs(A[a].second - A[c + 1].second) + dp[c + 1][b] == dp[a][b]) {
		cout << "1" << "\n";
		mem(c + 1, b, c + 1);
	}
	else {
		cout << "2" << "\n";
		mem(a, c + 1, c + 1);
	}
}

inline int solve(int a, int b, int c) {
	int& ref = dp[a][b];
	if (ref != -1) return ref;

	if (c == W) {
		return ref = 0;
	}

	int minA = abs(A[a].first - A[c + 1].first) + abs(A[a].second - A[c + 1].second) + solve(c + 1, b, c + 1);
	int minB = abs(B[b].first - B[c + 1].first) + abs(B[b].second - B[c + 1].second) + solve(a, c + 1, c + 1);

	return ref = min(minA, minB);
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> N;
	cin >> W;

	A[0].first = 1;
	A[0].second = 1;
	B[0].first = N;
	B[0].second = N;

	for (int i = 1; i <= W; ++i) {
		cin >> A[i].first;
		cin >> A[i].second;
		B[i] = A[i];
	}

	cout << solve(0, 0, 0) << "\n";
	mem(0, 0, 0);

	return EXIT_SUCCESS;
}