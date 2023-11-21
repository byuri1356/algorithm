#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int64 a, b;
	cin >> a >> b;

	cout << (a + b) * (a - b);

	return EXIT_SUCCESS;
}