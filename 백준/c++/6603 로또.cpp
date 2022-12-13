#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 Ans =INF;
vector<int64>v, v1;

inline void Solve(int64 N, int64 cur) {
	if (!N) {
		for (auto _iter : v1) {
			cout << _iter << ' ';
		}
		cout << "\n";
		return;
	}
	for (int64 i = cur; i < v.size(); ++i) {
		v1.push_back(v[i]);
		Solve(N - 1, i + 1);
		v1.pop_back();
	}
}

int main() {
	fastio;
	
	int64 T = 1, t, res = 0;
	do {
		cin >> T;
		for (int64 i = 0; i < T;) {
			cin >> t;
			v.push_back(t);
			++i;
		}
		Solve(6, 0);
		v.clear();
		cout << "\n";
	} while (T);

	return EXIT_SUCCESS;
}