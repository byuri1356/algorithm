#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;




int main() {

	fastio;

	ll X, N, S = 0;
	cin >> X >> N;

	while (N--) {
		ll a, b;
		cin >> a >> b;

		S += a * b;
	}

	if (X == S) cout << "Yes";
	else cout << "No";
	
}