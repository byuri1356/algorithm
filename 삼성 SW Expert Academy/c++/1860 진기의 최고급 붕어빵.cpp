#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using int64 = int64_t;

vector<int64> v;

int main() {
	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 N, M, K;
		cin >> N >> M >> K;

		v.clear();
		for (int64 i = 0; i < N; ++i) {
			int64 n;
			cin >> n;
			v.push_back(n);
		}

		sort(v.begin(), v.end());

		bool isSelect = true;
		for (int64 i = 0; i < N; ++i) {
			if ((v[i] / M) * K < i + 1) {
				isSelect = false;
				break;
			}
		}

		if (isSelect) {
			cout << '#' << t << ' ' << "Possible" << "\n";
		}
		else {
			cout << '#' << t << ' ' << "Impossible" << "\n";
		}

	}


	return EXIT_SUCCESS;
}