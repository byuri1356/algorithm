#include <iostream>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	if (a + b == c || b + c == a || c + a == b) cout << 1;
	else if (a * b == c || b * c == a || c * a == b) cout << 2;
	else cout << 3;
}