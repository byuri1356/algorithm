#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int64 arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int64 i = 2; i <= 37;) { 
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
				for (int64 j = 2*i; j <= 1000;) {
					arr[j] = 2;
					j += i;
				}
			}
		}
		++i;
	}
	for (int64 i = 2; i <= 1000;) {
		if (arr[i] == 0)
			arr[i] = 1;
		++i;
	}

	int64 T, t, ans=0;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		if (arr[t] == 1) {
			ans++;
		}
			
		++i;
	}
	cout << ans;

	return EXIT_SUCCESS;
}