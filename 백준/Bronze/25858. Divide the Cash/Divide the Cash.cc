#include<iostream>

using namespace std;



int main() {

	int n, m, d[30], sum = 0; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> d[i], sum += d[i];
	}

	for (int i = 0; i < n; ++i) cout << m / sum * d[i] << "\n";

	return 0;
}