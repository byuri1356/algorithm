#include<iostream>
using namespace std;
using int64 = int64_t;

inline void _solve() {

	int64 N, D;
	cin >> N >> D;

	if (N % (2 * D + 1) == 0)
		cout << N / (2 * D + 1) << "\n";
	else
		cout << N / (2 * D + 1) + 1 << "\n";
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	cin >> T;
	for (int64 test_case = 1; test_case <= T;) {


		cout << "#" << test_case << " ";  _solve();
		++test_case;
	}

	return EXIT_SUCCESS;
}