#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int N;

int main() {
	fastio;
	
	while (true) {
		cin >> N;
		if (!N) break;

		cout << N * (N + 1) / 2 << "\n";
	}


	return EXIT_SUCCESS;
}