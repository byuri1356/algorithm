#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	double a; cin >> a;

	cout << fixed;
	cout.precision(2);
	cout << a / 4;

	return 0;
}