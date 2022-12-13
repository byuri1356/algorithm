#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v;
bool _visit[9];

inline void Solve(int64 A,int64 B, int64 S) {
	if (S == 0) {
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		cout << "\n";
	}
	else {
		for (int64 i = B; i <= A; ++i) {
			if (_visit[i]) continue;
			v.push_back(i); _visit[i] = true;
			Solve(A, i + 1, S - 1);
			v.pop_back(); _visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t;
	cin >> T >> t;
	Solve(T,1, t);

	return EXIT_SUCCESS;
}