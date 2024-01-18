#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int dp[4002][4002];

int main() {

	fastio;

	int answer = 0;
	string a, b; cin >> a >> b;

	a = '#' + a;
	b = '@' + b;

	for (int i = 1; i < a.size(); ++i) {
		for (int j = 1; j < b.size(); ++j) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1, answer = max(answer, dp[i][j]);
		}
	}

	cout << answer;
}