#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v,m;

inline void Solve(int64 A, int64 B, int64 S) {
	if (S == 0) {
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		cout << "\n";
	}
	else {
		for (int64 i = B; i < m.size(); ++i) {
			v.push_back(m[i]);
			Solve(A, i, S - 1);
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t, a;
	cin >> T >> t;
	for (int64 i = 0; i < T;) {
		cin >> a;
		m.push_back(a);
		++i;
	}
	sort(m.begin(), m.end());
	Solve(T, 0, t);

	return EXIT_SUCCESS;
}