#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int main() {
	fastio;

	int64 T, sc;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		cin >> sc;

		vector<pair<int64, int64>> v;
		for (int64 i = 0; i < 101; ++i) {
			v.push_back({ 0, i });
		}

		for (int64 i = 0; i < 1000; ++i) {
			cin >> sc;
			v[sc].first++;
		}

		sort(v.begin(), v.end());

		cout << "#" << t << ' ' << v[v.size()-1].second << "\n";

	}

	return EXIT_SUCCESS;
}