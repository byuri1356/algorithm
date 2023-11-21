#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
using int64 = int64_t;

int arr[1001];
int dp[1001];

inline void Solve(int T) {
	if (T == 1) {
		return;
	}
	
	for (int i = 2; i <= T;) {
		int _max = 0;
		for (int j = i - 1; j > 0;) {
			if (arr[i] > arr[j]) {
				_max = max(_max, dp[j]+1);
			}
			--j;
		}
		dp[i] = _max;
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ) {
		cin >> arr[i];
		++i;
	}

	Solve(T);

	int _max = 0;
	for (int i = 1; i <= T; ) {
		_max = max(_max, dp[i]);
		++i;
	}
	cout << _max+1;
}