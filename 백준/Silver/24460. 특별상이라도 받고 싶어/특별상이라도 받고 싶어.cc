#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1025][1025];
vector<int64> v;

inline int64 recursion(int64 pre_X, int64 pre_Y, int64 next_X, int64 next_Y, int64 _size) {
	if (((pre_X+1) == next_X) && ((pre_Y+1) == next_Y)) {
		int64 sec;
		v.push_back(arr[pre_X][pre_Y]);
		v.push_back(arr[pre_X][next_Y]);
		v.push_back(arr[next_X][pre_Y]);
		v.push_back(arr[next_X][next_Y]);
		sort(v.begin(), v.end());
		sec = v[1];
		v.clear();
		return sec;
	}
	int64 quad1 = recursion(pre_X, pre_Y, pre_X + (_size / 2) - 1, pre_Y + (_size / 2) - 1, _size / 2);
	int64 quad2 = recursion(pre_X, pre_Y + (_size / 2), pre_X + (_size / 2) - 1, pre_Y + _size - 1, _size / 2);
	int64 quad3 = recursion(pre_X + (_size / 2), pre_Y, pre_X + _size - 1, pre_Y + (_size / 2) - 1, _size / 2);
	int64 quad4 = recursion(pre_X + (_size / 2), pre_Y + (_size / 2), pre_X + _size - 1, pre_Y + _size - 1, _size / 2);

	int64 sec1;
	v.push_back(quad1);
	v.push_back(quad2);
	v.push_back(quad3);
	v.push_back(quad4);
	sort(v.begin(), v.end());
	sec1 = v[1];
	v.clear();
	return sec1;
}

int main() {
	fastio;
	
	int64 T;
	cin >> T;
	if (T != 1) {
		for (int64 i = 1; i <= T;) {
			for (int64 j = 1; j <= T;) {
				cin >> arr[i][j];
				++j;
			}
			++i;
		}

		int64 Ans = recursion(1, 1, T, T, T);
		cout << Ans;
	}
	else {
		cin >> arr[0][0];
		cout << arr[0][0];
	}

	return EXIT_SUCCESS;
}