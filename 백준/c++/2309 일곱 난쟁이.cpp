#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

bool s;
vector<int> v,v1;

inline void Select(int64 sel, int64 rg, int64 rem) {
	if (rem < 0) {
		return;
	}
	else if (rem == 0) {
		if (sel == 0) {
			s = true;
			for (auto _iter : v1) {
				cout << _iter << "\n";
			}
		}
	}

	for (int64 i = rg; i < v.size();) {
		v1.push_back(v[i]);
		Select(sel - 1, rg + 1, rem - v[i]);
		if (s) {
			break;
		}
		v1.pop_back();
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	for (int64 i = 0; i < 9;) {
		cin >> T; v.push_back(T);
		++i;
	}
	sort(v.begin(), v.end());

	Select(7, 0, 100);
	return EXIT_SUCCESS;
}