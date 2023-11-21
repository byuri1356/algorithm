#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int a, b, diff;

int main() {

	fastio;

	int a, b; cin >> a >> b;

	if (a >= 3 && b <= 4) cout << "TroyMartian" << "\n";
	if (a <= 6 && b >= 2) cout << "VladSaturnian" << "\n";
	if (a <= 2 && b <= 3) cout << "GraemeMercurian" << "\n";

}