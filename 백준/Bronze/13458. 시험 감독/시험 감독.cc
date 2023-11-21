#include <iostream>
#include<vector>
using namespace std;
using int64 = int64_t;

int64 A[1'000'000];
int64 Min;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, B, C;
	cin >> T;

	for (int64 test_case = 0; test_case < T; ) {
		cin >> A[test_case];
		++test_case;
	}
	cin >> B >> C;

	for (int64 test_case = 0; test_case < T;) {
		A[test_case] -= B;
		if (A[test_case] > 0) {
			if ((A[test_case] % C) != 0) {
				Min += 1;
			}
			Min += A[test_case] / C;
		}
		++test_case;
	}
	Min += T;

	cout << Min;
}