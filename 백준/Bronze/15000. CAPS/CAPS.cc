#include<iostream>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	string s;
	cin >> s;

	for (auto& it : s) {
		cout<< char(it - 'a' + 'A');
	}

	return EXIT_SUCCESS;
}