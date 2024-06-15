#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C; cin >> A >> B >> C;
	int K = (A + B + C) / 3;
	cout << (K - A) + (K - (B - (K - A)));
}