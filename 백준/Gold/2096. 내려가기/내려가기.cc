#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int a, b, c, n, tmpA, tmpB, tmpC, minA, minB, minC, maxA, maxB, maxC; cin >> n;

	cin >> a >> b >> c;

	minA = maxA = a;
	minB = maxB = b;
	minC = maxC = c;

	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;

		tmpA = min(minA, minB) + a;
		tmpB = min({ minA, minB, minC }) + b;
		tmpC = min(minB, minC) + c;

		minA = tmpA; minB = tmpB; minC = tmpC;

		tmpA = max(maxA, maxB) + a;
		tmpB = max({ maxA, maxB, maxC }) + b;
		tmpC = max(maxB, maxC) + c;

		maxA = tmpA; maxB = tmpB; maxC = tmpC;
	}

	cout << max({ maxA, maxB, maxC }) << " " << min({ minA, minB, minC });

}