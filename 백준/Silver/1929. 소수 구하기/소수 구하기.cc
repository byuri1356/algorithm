#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int64 arr[1'000'001] = { 2,2, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	for (int64 i = 2; i <= 1000; ) {
		if (arr[i] == 0) {
			for (int64 j = i - 1; j > 1;) {
				if ((i % j) == 0) {
					arr[i] = 2;
					break;
				}
				--j;
			}
			if (arr[i] != 2) {
				arr[i] = 1;
				for (int64 j = i * 2; j <= 1000000;) {
					arr[j] = 2;
					j += i;
				}
			}
		}
		++i;
	}
	
	int64 T, t;
	cin >> T >> t;
	for (int64 i = T; i <= t;) {
		if (arr[i] != 2)
			cout << i << "\n";
		++i;
	}

	return EXIT_SUCCESS;
}