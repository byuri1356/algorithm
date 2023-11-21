#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t, max = 0, min = 1'000'001;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		if (t > max)
			max = t;
		if (t < min)
			min = t;
		++i;
	}
	
	cout << max * min;

	return EXIT_SUCCESS;
}