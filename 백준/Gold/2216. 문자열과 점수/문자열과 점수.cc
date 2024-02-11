#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int a, b, c, dp[3001][3001];
string x, y;

int sol(int l, int r) {
	int& ref = dp[l][r];
	if (ref != -1) return ref;

	ref = -1e9;

	if (l < x.size() && r < y.size()) {
		if (x[l] == y[r]) ref = max(ref, a + sol(l + 1, r + 1));
		else ref = max(ref, c + sol(l + 1, r + 1));
		ref = max(ref, b + sol(l + 1, r));
		ref = max(ref, b + sol(l, r + 1));
	}
	else if (l < x.size()) {
		ref = max(ref, b + sol(l + 1, r));
	}
	else if (r < y.size()) {
		ref = max(ref, b + sol(l, r + 1));
	}

	return ref;
}



int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> a >> b >> c >> x >> y;

	dp[x.length()][y.length()] = 0;

	cout << sol(0, 0);

	//cout << "!";
}