#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

vector<int64>v;

int main() {
	fastio;
	
	int64 T, t, _count=0;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		v.push_back(t);
		++i;
	}
	
	for (int64 i = T - 1; i >= 0;) {
		if (v[i] == T - i) ++_count;
		--i;
	}
	if (_count == T) cout << -1;
	else {
		next_permutation(v.begin(), v.end());
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
	}

	return EXIT_SUCCESS;
}