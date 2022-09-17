#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int64 T, t;
	cin >> T >> t;
	for (int64 i = 1; ;) {
		if (((T * i) % t) == 1) {
			cout << i;
			break;
		}
		++i;
	}

	return EXIT_SUCCESS;
}