#include<iostream>
#include<ctime>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int a, b;
	cin >> a >> b;
	int c = a * (100 - b); 

	if (c >= 10000) cout << 0;
	else cout << 1;

	return 0;

}