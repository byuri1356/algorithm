#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int L, R;

	cin >> L >> R;
	while (L <= R) {
		cout << "All positions change in year " << L << '\n';
		L += 60;
	}

}