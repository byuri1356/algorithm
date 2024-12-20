#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;

		cout << a << ' ' << b << ' ' << c << '\n';

		if (a < 10 && b < 10 && c < 10)
			cout << "zilch\n\n";
		else if (a >= 10 && b >= 10 && c >= 10)
			cout << "triple-double\n\n";
		else if ((a >= 10 && b >= 10) || (b >= 10 && c >= 10) || (a >= 10 && c >= 10))
			cout << "double-double\n\n";
		else
			cout << "double\n\n";
	}

	return 0;
}