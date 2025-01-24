#include <iostream>
using namespace std;

int h1, b1, h2, b2;
int s1, s2;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> h1 >> b1 >> h2 >> b2;
	s1 = h1 * 3 + b1, s2 = h2 * 3 + b2;
	if (s1 > s2) cout << 1 << " " << s1 - s2;
	else if (s2 > s1) cout << 2 << " " << s2 - s1;
	else cout << "NO SCORE";
}