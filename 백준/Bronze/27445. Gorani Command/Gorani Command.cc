#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int N, M, Cmp;
	cin >> N >> M;

	int minx = 100000, xidx = -1;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> Cmp;
		if (Cmp < minx) {
			minx = Cmp;
			xidx = i;
		}
	}

	int miny = 100000, yidx = -1;

	cin >> Cmp;
	if (Cmp < minx) {
		minx = Cmp;
		xidx = N;
	}
	if (Cmp < miny) {
		miny = Cmp; 
		yidx = 1;
	}

	for (int i = 2; i <= M; ++i) {
		cin >> Cmp;
		if (Cmp < miny) {
			miny = Cmp;
			yidx = i;
		}
	}

	cout << xidx << ' ' << yidx;

	return EXIT_SUCCESS;
}