#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int a, b;
	cin >> a >> b;

	int c = 9 * 60, d = a * 60 + b;

	d = d - c;

	cout << d << "\n";
	
}