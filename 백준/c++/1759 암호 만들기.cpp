#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<char> v,v1;

inline void Solve(int64 S, int64 rm, int64 am, int64 pos) {
	if (rm < 0)rm = 0;
	if (am < 0) am = 0;
	if (S - rm - am < 0)return;
	else if (S == 0) {
		for (auto _iter : v1) {
			cout << _iter;
		}
		cout << "\n";
		return;
	}
	for (int64 i = pos; i < v.size(); ++i) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			v1.push_back(v[i]);
			Solve(S - 1, rm - 1, am, i + 1);
			v1.pop_back();
		}
		else {
			v1.push_back(v[i]);
			Solve(S - 1, rm, am - 1, i + 1);
			v1.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 L, C;
	char a;
	cin >> L >> C;
	for (int64 i = 0; i < C;) {
		cin >> a;
		v.push_back(a);
		++i;
	}
	sort(v.begin(), v.end());
	Solve(L, 1, 2, 0);

	return EXIT_SUCCESS;
}