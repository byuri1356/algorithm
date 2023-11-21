#include<iostream>
#include<vector>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

bool dp[500][100000];
int mem[100000];

int main() {

	fastio;

	string s;
	cin >> s;

	int N, slen = s.length();
	cin >> N;

	vector<int> tlen(N);

	for (int i = 0; i < N; ++i) {
		string t;
		cin >> t;
		tlen[i] = t.length();

		vector<int> pi(tlen[i]);

		int k = 0;
		for (int j = 1; j < tlen[i]; ++j) {
			while (k > 0 && t[k] != t[j]) {
				k = pi[k - 1];
			}

			if (t[k] == t[j]) {
				pi[j] = ++k;
			}
		}
		
		k = 0;
		for (int j = 0; j < slen; ++j) {
			while (k > 0 && t[k] != s[j]) {
				k = pi[k - 1];
			}

			if (t[k] == s[j]) {
				if (k == tlen[i] - 1) {
					dp[i][j - tlen[i] + 1] = true;
					k = pi[k];
				}
				else {
					++k;
				}
			}
		}
	}

	for (int j = 0; j < N; ++j) {
		if (dp[j][0]) {
			mem[tlen[j] - 1] = tlen[j];
		}
	}

	for (int i = 1; i < slen; ++i) {
		for (int j = 0; j < N; ++j) {
			mem[i] = max(mem[i], mem[i - 1]);
			if (dp[j][i]) mem[i + tlen[j] - 1] = max(mem[i + tlen[j] - 1], mem[i - 1] + tlen[j]);
		}
	}

	cout << mem[slen - 1];

	return EXIT_SUCCESS;
}