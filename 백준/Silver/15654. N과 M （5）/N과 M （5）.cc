#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v,m;
bool _visit[9];

inline void Solve(int64 A, int64 S) {
	if (S == 0) {
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		cout << "\n";
	}
	else {
		for (int64 i = 0; i < m.size(); ++i) {
			if (_visit[i]) continue;
			v.push_back(m[i]); _visit[i] = true;
			Solve(A, S - 1);
			v.pop_back(); _visit[i] = false;
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
	Solve(T, t);

	return EXIT_SUCCESS;
}