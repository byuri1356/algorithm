#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

vector<int64> v[100'001];
pair<int64, int64> p[100'001];
queue< pair<int64, bool>> q;

inline void Solve() {
	int64 ans = 0, Ans = 0;
	while (!q.empty()) {
		int64 a = q.front().first;
		bool b = q.front().second;
		q.pop();

		if (b) {
			ans += p[a].first;
			Ans += p[a].second;
		}
		else {
			ans += p[a].second;
			Ans += p[a].first;
		}
		
		for (auto _iter : v[a]) {
			q.push({ _iter, !b });
		}
	}
	cout << min(ans, Ans);
}

int main() {
	fastio;

	int64 T, a, b;
	cin >> T;
	for (int64 i = 0; i < T-1;) {
		cin >> a >> b;
		v[a].push_back(b);
		++i;
	}
	for (int64 i = 0; i < T;) {
		cin >> p[i].first >> p[i].second;
		++i;
	}

	q.push({ 0, true });
	Solve();
	
	return EXIT_SUCCESS;
}