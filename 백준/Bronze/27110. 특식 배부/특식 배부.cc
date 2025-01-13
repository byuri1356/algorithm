#include <iostream>
using namespace std;

int chick[3];
int main() {
	
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> chick[i];
		if (chick[i] >= n) {
			sum += n;
		}
		else {
			sum += chick[i];
		}
	}

	cout << sum << "\n";
}