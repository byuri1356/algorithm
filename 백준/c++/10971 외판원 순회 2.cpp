#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 Ans =INF;
int64 arr[11][11];
vector<int64>v;

int main() {
	fastio;
	
	int64 T, t, res = 0;
	cin >> T;
	for (int64 i = 1; i <= T;) {
		for (int64 j = 1; j <= T;) {
			cin >> arr[i][j];
			if ((i != j) && (arr[i][j] == 0)) arr[i][j] = INF;
			++j;
		}
		v.push_back(i);
		++i;
	}
	
	do {
		int64 i = 0;
		for (i = 0; i < v.size() - 1; ) {
			res += arr[v[i]][v[i + 1]];
			++i;
		}
		res += arr[v[i]][v[0]];
		Ans = min(Ans, res);
		res = 0;
	} while (next_permutation(v.begin(), v.end()));

	cout << Ans;
	return EXIT_SUCCESS;
}