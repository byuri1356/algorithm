#include <iostream>
using namespace std;
typedef long long ll;

ll r, c;
ll A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	A = r * c;

	cout << (A - 1) / 24200 + 1;
}