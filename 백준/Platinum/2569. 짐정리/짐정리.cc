#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int N, ans = 0;
	cin >> N;

	vector<bool> ch(N);
	vector<pair<int, int>> vp(N);

	for (int i = 0; i < N; ++i) {
		cin >> vp[i].first;
		vp[i].second = i;
	}

	sort(vp.begin(), vp.end());

	for (int i = 0; i < N; ++i) {
		if (ch[i]) continue;

		int cnt = 0;
		for (int j = i; !ch[j]; j = vp[j].second) {
			cnt++;
			ch[j] = true;
			ans += vp[j].first;
		}

		ans += min(vp[i].first * (cnt - 2), vp[0].first * (cnt + 1) + vp[i].first);
	}

	cout << ans;

	return EXIT_SUCCESS;
}