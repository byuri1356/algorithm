#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

struct dat {
	int64 w = 0, s = 0, e = 0;
};

bool cmpW(dat o1, dat o2) {
	if (o1.w != o2.w) return o1.w < o2.w;
	return o1.s < o2.s;
}

bool cmpS(dat o1, dat o2) {
	return o1.s < o2.s;
}

int main() {

	fastio;

	int64 N, ans = 0;
	cin >> N;

	vector<bool> ck(N + 1);
	vector<dat> w(N + 1), s(N + 1);

	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		w[i].w = s[i].w = a;
	}

	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		w[a].s = s[a].s = i;
	}

	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		w[a].e = s[a].e = i;
	}

	sort(w.begin(), w.end(), cmpW);
	sort(s.begin(), s.end(), cmpS);

	for (int i = 1; i <= N; ++i) { 
		if (ck[w[i].e]) continue;

		int cnt = 0;
		for (int j = w[i].s; !ck[s[j].e]; j = s[j].e) {
			cnt++;
			ck[s[j].e] = true;
			ans += s[j].w;
		}

		ans += min(w[i].w * (cnt - 2), w[1].w * (cnt + 1) + w[i].w);
	}

	cout << ans;

	return EXIT_SUCCESS;
}