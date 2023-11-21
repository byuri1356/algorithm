#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << (a * a + b * b + c * c + d * d + e * e) % 10;

	return EXIT_SUCCESS;
}