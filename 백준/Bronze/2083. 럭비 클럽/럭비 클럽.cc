#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	while (1) {
		string s;
		int a, b;
		cin >> s >> a >> b;

		if (s == "#") break;

		if (a > 17 || b >= 80) cout << s << " " << "Senior" << "\n";
		else cout << s << " " << "Junior" << "\n";
	}


}