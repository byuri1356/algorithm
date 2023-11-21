#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int a, ans = 0;
	cin >> a;

	for (int i = 1; i <= 1000001; ++i) {
		int cmp = i;
		int I = i;
		while (I) {
			cmp += I % 10;
			I /= 10;
		}

		if (a == cmp) {
			ans = i; 
			break;
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}