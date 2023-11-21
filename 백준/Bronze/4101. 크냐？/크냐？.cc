#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 a, b;

	for(;;){
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (a > b) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}

	return EXIT_SUCCESS;
}