#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 N;
	cin >> N;
	
	if (!(N % 400)) {
		cout << 1;
	}
	else if (!(N % 100)) {
		cout << 0;
	}
	else if (!(N % 4)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return EXIT_SUCCESS;
}