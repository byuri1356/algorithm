#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	string s;
	cin >> s;
	for (int i = s.length()-1; i >= 0; --i) {
		cout << s[i];
	}

	return EXIT_SUCCESS;
}