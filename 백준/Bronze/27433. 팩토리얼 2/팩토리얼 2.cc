#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	ll N, fac[21] = { 1, }; cin >> N;

	for (int i = 1; i <= N; ++i) {
		fac[i] = fac[i - 1] * i;
	}
	
	cout << fac[N];

	return 0;
}