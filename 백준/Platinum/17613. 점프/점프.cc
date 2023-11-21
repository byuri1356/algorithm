#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

map<pair<int, int>, int> dp;

//30 = 10억 얼마얼마..
int solve(int st, int ed) {
	if (!st && !ed) return 0;
	if (dp.find({ st, ed }) != dp.end()) return dp[{st, ed}];

	int sum = 0;

	for (int i = 1; i < 30; ++i) {
		int lt = (1 << i) - 1;
		int rt = (1 << i + 1) - 2;

		//왼쪽은 큰값 따라가고, 오른쪽은 작은값 따라감
		int left = max(st, lt);
		int right = min(ed, rt);

		int l = left - lt;
		int r = right - lt;

		//구간이 아예 안겹치는 경우 제외
		if (left <= right) {
			sum = max(sum, solve(l, r) + i);
		}
	}

	return dp[{st, ed}] = sum;
}

int main() {

	fastio;

	int T;
	cin >> T;

	while (T--) {
		int st, ed;
		cin >> st >> ed;

		cout << solve(st, ed) << "\n";
	}

	return EXIT_SUCCESS;
}