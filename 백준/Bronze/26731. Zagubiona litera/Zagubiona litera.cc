#include <iostream>
using namespace std;

bool arr[128];
char c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> c) arr[c] = 1;

	for (char cc = 'A'; cc <= 'Z'; cc++) {
		if (!arr[cc]) cout << cc;
	}
}