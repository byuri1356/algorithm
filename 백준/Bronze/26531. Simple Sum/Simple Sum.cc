#include <iostream>
#include <string>
using namespace std;

int a, b, c; char x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> x >> b >> x >> c;
	if (a + b == c) cout << "YES";
	else cout << "NO";
}