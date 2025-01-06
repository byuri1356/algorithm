#include <iostream>
using namespace std;
typedef long double ld;

int T;
ld A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed;
	cout.precision(2);

	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << "The height of the triangle is " << (2 * A) / B << " units\n";
	}
}