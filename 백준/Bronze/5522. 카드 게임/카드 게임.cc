#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int a;
		cin >> a;
		sum += a;
	}

	cout << sum;

	return EXIT_SUCCESS;
}