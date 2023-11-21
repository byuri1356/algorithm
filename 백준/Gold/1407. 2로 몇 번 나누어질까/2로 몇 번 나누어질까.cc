#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 A, B, startP, endP, dep = 0, res, ans = 0;
	cin >> A >> B;

	startP = A;
	endP = B;
	res = endP - startP + 1;

	while (endP) {
		int64 ress = endP - startP + 1;

		if (res != ress) {
			ans += (res - ress) * (int64)pow(2, dep - 1);
			res = ress;
		}

		if (startP % 2) startP++;
		if (endP % 2) endP--;

		startP /= 2;
		endP /= 2;
		dep++;
	}

	ans += res * (int64)pow(2, dep - 1);

	cout << ans;

	return EXIT_SUCCESS;
}