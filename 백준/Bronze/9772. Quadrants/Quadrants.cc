#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	while (true) {
		double a, b; cin >> a >> b;

		if (a == 0 && b == 0) break;

		if (a == 0 || b == 0) cout << "AXIS" << "\n";
		else if (0 < a && 0 < b) cout << "Q1" << "\n";
		else if (a < 0 && 0 < b) cout << "Q2" << "\n";
		else if (a < 0 && b < 0) cout << "Q3" << "\n";
		else cout << "Q4" << "\n";
	}

	cout << "AXIS" << "\n";
	



}