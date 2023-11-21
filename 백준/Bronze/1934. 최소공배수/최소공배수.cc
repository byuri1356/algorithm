#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;

inline int64 Solve(int64 a, int64 b) {
	a = a % b;
	if (a == 0)
		return b;
	else {
		return Solve(b, a);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, a, b;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> a >> b;
		cout<<a*b/Solve(a,b)<<'\n';
		++i;
	}

	return EXIT_SUCCESS;
}