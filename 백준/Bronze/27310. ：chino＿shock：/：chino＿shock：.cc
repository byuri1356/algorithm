#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

char _ch;

int main() {
	fastio;

	int i = 0, sum = 0, tk=2;
	while(tk){
		cin >> _ch;
		if (_ch == ':') tk--;
		else if (_ch == '_') sum++;
		++i;
	}

	cout << i + 2 + sum * 5;

	return EXIT_SUCCESS;
}