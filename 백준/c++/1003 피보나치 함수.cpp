#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using int64 = int64_t;

pair<int64, int64> p[41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	p[0].first = 1;
	p[0].second = 0;
	p[1].first = 0;
	p[1].second = 1;

	for (int64 i = 2; i < 41;) {
		p[i].first = p[i - 1].first + p[i - 2].first;
		p[i].second = p[i - 1].second + p[i - 2].second;
		++i;
	}

	int64 T,t;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		cout << p[t].first  << ' ' << p[t].second << "\n";
		++i;
	}

	return EXIT_SUCCESS;
}