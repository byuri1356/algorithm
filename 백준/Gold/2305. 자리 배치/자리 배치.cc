#include<iostream>
#include<memory.h>
using namespace std;

int n, k, ans, dp[42][4][4][2];

int sol(int idx, int pprev, int prev, int pv) {

	int& ref = dp[idx][pprev][prev][pv];

	if (idx == n + 1) return ref = 1;
	if (ref != -1) return ref;
	ref = 0;

	if (idx == k) return ref = sol(idx + 1, pprev, prev, pv);
	if (pv) ref += sol(idx + 1,prev, 3, 0);
	if (prev != 2) ref += sol(idx + 1, prev, 0, pv);
	if (prev != 0 && pprev != 2 && idx - 1 != k && 1<= idx - 1) ref += sol(idx + 1, prev, 1, pv);
	if (idx + 1 != k && idx + 1 <=n) ref += sol(idx + 1, prev, 2, pv);

	return ref;
}

int main() {
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));

	cout << sol(1, -1, -1, 1);

}