#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using int64 = int64_t;

vector<int64> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	for (int64 i = 1; i <= 10; ++i) {
		int64 N, n;
		cin >> N;

		for (int64 j = 0; j < 100; ++j) {
			cin >> n;
			v.push_back(n);
		}

		for (int64 j = 0; j < N; ++j) {
			sort(v.begin(), v.end());
			if (v[99] - v[0] <= 1) break;
			v[0] += 1; v[99] -= 1;
		}

		sort(v.begin(), v.end());
		cout << '#' << i << ' ' << v[99] - v[0] << "\n";
		v.clear();
	}

	return EXIT_SUCCESS;
}