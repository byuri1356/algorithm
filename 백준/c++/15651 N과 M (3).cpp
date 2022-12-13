#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v;

inline void Solve(int64 A, int64 S) {
	if (S == 0) {
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		cout << "\n";
	}
	else {
		for (int64 i = 1; i <= A; ++i) {
			v.push_back(i); 
			Solve(A, S - 1);
			v.pop_back(); 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t;
	cin >> T >> t;
	Solve(T, t);

	return EXIT_SUCCESS;
}