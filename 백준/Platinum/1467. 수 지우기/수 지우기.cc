#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int tCnt[10], sCnt[10], cCnt[10];

int main() {

	fastio;

	string s, t;
	cin >> s >> t;

	vector<int> v[10];

	for (int i = 0; i < s.length(); ++i) sCnt[s[i] - '0']++, v[s[i] - '0'].push_back(i);

	for (int i = 0; i < t.length(); ++i) tCnt[t[i] - '0']++, sCnt[t[i] - '0']--;

	int idx = 0, len = s.length() - t.length();

	while (len--) {
		for (int i = 9; i >= 0; --i) {
			if (!sCnt[i]) continue;

			int iidx = lower_bound(v[i].begin(), v[i].end(), idx) - v[i].begin();

			vector<int> sz(10);
			for (int j = idx; j < v[i][iidx]; ++j) sz[s[j] - '0']++;

			bool ch = true;
			for (int j = 9; j >= 0; --j) {
				if (sz[j] > tCnt[j]) {
					ch = false;
					break;
				}
			}
			
			if (ch) {
				for (int j = 9; j >= 0; --j) tCnt[j] -= sz[j];
				cout << i;
				sCnt[i]--;
				idx = v[i][iidx] + 1;
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}