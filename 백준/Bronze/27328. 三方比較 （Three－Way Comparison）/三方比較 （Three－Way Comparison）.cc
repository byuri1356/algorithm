#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int a, b; cin >> a >> b;

	if (a < b) cout << "-1";
	else if (b < a) cout << "1";
	else cout << 0;

	return 0;
}