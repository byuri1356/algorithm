#include<iostream>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int N, lockA[104], lockB[104], dp[104][10][10][10][2];

int mod(int num) {
	return (num + 10) % 10;
}

int sol(int idx, int n1, int n2, int n3, int dir) {

	int& ref = dir == 1 ? dp[idx][n1][n2][n3][1] : dp[idx][n1][n2][n3][0];

	if (ref != -1) return ref;
	if (idx == N) return 0;

	ref = 1e8;

	if (lockB[idx] == n1) 
		return ref = min(sol(idx + 1, n2, n3, lockA[idx + 3], -1), sol(idx + 1, n2, n3, lockA[idx + 3], 1));

	for (int i = 1; i < 4; ++i) {
		int rot = i * dir;
		ref = min(ref, sol(idx, mod(n1 + rot), n2, n3, dir) + 1);
		ref = min(ref, sol(idx, mod(n1 + rot), mod(n2 + rot), n3, dir) + 1);
		ref = min(ref, sol(idx, mod(n1 + rot), mod(n2 + rot), mod(n3 + rot), dir) + 1);
	}

	return ref;

}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> N; cin.get();

	for (int i = 0; i < N; ++i) lockA[i] = cin.get() - '0'; cin.get();
	for (int i = 0; i < N; ++i) lockB[i] = cin.get() - '0';

	cout << min(sol(0, lockA[0], lockA[1], lockA[2], 1), sol(0, lockA[0], lockA[1], lockA[2], -1));

	//cout << "!";
}