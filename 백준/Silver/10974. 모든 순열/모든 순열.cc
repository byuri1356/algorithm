#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

vector<int64>v;

int main() {
	fastio;
	
	int64 T, t, _count=0;
	cin >> T;
	for (int64 i = 0; i < T;) {
		v.push_back(i+1);
		++i;
	}
	
	do {
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return EXIT_SUCCESS;
}