#include<iostream>
#include<vector>
#include<string>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int main() {

	fastio;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		cout << s[0] << s[s.length() - 1] << "\n";
	}

	return EXIT_SUCCESS;
}