#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;


int main() {
	fastio;

	int64 N, minn = INF, min_x = 0, min_y = 0;
	pair<int64, int64> Arr[1000];


	cin >> N;
	for (int64 i = 0; i < N; ++i) {
		cin >> Arr[i].first;
		cin >> Arr[i].second;
	}

	for (int64 i = 0; i < N; ++i) {
		int64 maxx = 0, max_x = 0, max_y = 0;
		for (int64 j = 0; j < N; ++j) {
			if (i == j) continue;
			int64 tmp = abs(Arr[i].first - Arr[j].first) * abs(Arr[i].first - Arr[j].first) + abs(Arr[i].second - Arr[j].second) * abs(Arr[i].second - Arr[j].second);

			if (tmp > maxx) {
				maxx = tmp;
			}
		}

		if (maxx < minn) {
			minn = maxx;
			min_x = Arr[i].first;
			min_y = Arr[i].second;
		}
	}

	cout << min_x << " " << min_y;

	return EXIT_SUCCESS;
}

