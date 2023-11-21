#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	double A, B;
	cin >> A >> B;
	cout << fixed;
	cout.precision(15);
	cout << A / B;

	return EXIT_SUCCESS;
}