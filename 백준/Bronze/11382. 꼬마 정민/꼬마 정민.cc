#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int main() {

	fastio;

	int64 a, b, c;
	cin >> a >> b >> c;

	cout << a + b + c;

	return EXIT_SUCCESS;
}