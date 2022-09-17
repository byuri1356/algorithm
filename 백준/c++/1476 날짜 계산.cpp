#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 E, S, M, a, b, c;
	cin >> E >> S >> M;
	
	for (int64 i = 1;;) {
		a = i % 15; b = i % 28; c = i % 19;
		if (a == 0) {
			a = 15;
		}
		if (b == 0) {
			b = 28;
		}
		if (c == 0) {
			c = 19;
		}
		if ((a == E) && (b == S) && (c == M)) {
			cout << i;
			break;
		}
		++i;
	}
	
	return EXIT_SUCCESS;
}