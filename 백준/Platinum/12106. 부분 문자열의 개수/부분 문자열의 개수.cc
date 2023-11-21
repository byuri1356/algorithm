#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

const int MOD = 1e9 + 9;

int N;
int64 dp[101][101][26];
vector<int> pi;
string s;

int64 solve(int idx, int fail, int alpha) {
	int64& ref = dp[idx][fail][alpha];

	if (ref != -1) return ref;

	if (idx == N) {
		if (fail == s.length() - 1) return ref = 1;
		return ref = 0;
	}

	ref = 0;
	for (int i = 0; i < 26; ++i) {
		int j = fail;
		if (j == s.length() - 1) {
			ref += solve(idx + 1, j, i);
			ref %= MOD;
			continue;
		}

		while (j && s[j + 1] - 'a' != i) {
			j = pi[j];
		}

		if (s[j + 1] - 'a' == i) {
			ref += solve(idx + 1, j + 1, i);
		}
		else {
			ref += solve(idx + 1, 0, i);
		}

		ref %= MOD;
	}

	return ref;
}

void makePi() {
	for (int i = 1, j = 0; i < s.length(); ++i) {
		while (j && s[j] != s[i]) {
			j = pi[j];
		}

		if (s[j] == s[i]) {
			pi[i + 1] = ++j;
		}
	}
}

int main() {

	fastio;

	cin >> N >> s;

	pi.resize(N + 1);
	makePi();
	s = "@" + s;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0) % MOD;

	return EXIT_SUCCESS;
}