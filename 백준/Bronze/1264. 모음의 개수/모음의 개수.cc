#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	while (1) {
		int ans = 0;
		string s;
		getline(cin, s);

		if (s == "#") break;
		for (auto& it : s) {
			if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') ans++;
			else if (it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') ans++;
		}

		cout << ans<<"\n";
	}


}