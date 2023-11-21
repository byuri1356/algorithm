#include<iostream>
#include<vector>
#include<tuple>
#include<memory.h>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M, ans;
vector<int> v;
int mp[302][302][2];

int solve(int l, int r, int s, int i) {
	if (!i) return 0;
	int& ret = mp[l][r][s];
	if (ret != -1) return ret;

	ret = INT32_MAX;

	if (l) {
		ret = min(ret, i * ((s ? v[r] : v[l]) - v[l - 1]) + solve(l - 1, r, 0, i - 1));
	}
	if (r < N) {
		ret = min(ret, i * (v[r + 1] - (s ? v[r] : v[l])) + solve(l, r + 1, 1, i - 1));
	}

	return ret;
}

int main() {

	fastio;

	cin >> N >> M;

	v.resize(N);

	for(int i=0; i<N; ++i) cin >> v[i];

	v.push_back(0);
	sort(v.begin(), v.end());

	int st = lower_bound(v.begin(), v.end(), 0) - v.begin();
	for (int i = 1; i <= N; ++i) {
		memset(mp, -1, sizeof mp);
		ans = max(ans, i * M - solve(st, st, 0, i));
	}

	cout << ans;

	return EXIT_SUCCESS;
}