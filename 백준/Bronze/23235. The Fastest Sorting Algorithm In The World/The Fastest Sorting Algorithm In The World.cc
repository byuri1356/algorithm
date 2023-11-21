#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int cnt = 1;
	string s;
	while (true) {
		getline(cin, s);
		if (s == "0") break;
		cout << "Case " << cnt++ << ": " << "Sorting... done!" << "\n";
	}

	return EXIT_SUCCESS;
}