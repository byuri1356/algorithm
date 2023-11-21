#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 Ans;
vector<int64>v;

int main() {
	fastio;
	
	int64 T, t, res = 0;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		v.push_back(t);
		++i;
	}
	
	sort(v.begin(), v.end());
	do {
		for (int64 i = 0; i < v.size() - 1; ) {
			res += abs(v[i] - v[i + 1]);
			++i;
		}
		Ans = max(Ans, res);
		res = 0;
	} while (next_permutation(v.begin(), v.end()));

	cout << Ans;
	return EXIT_SUCCESS;
}