#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0) break;

		cout << a + b << "\n";
	}

}