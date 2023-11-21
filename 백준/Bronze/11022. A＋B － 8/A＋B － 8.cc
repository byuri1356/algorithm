#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;


int main() {

	fastio;

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << t << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return EXIT_SUCCESS;
}