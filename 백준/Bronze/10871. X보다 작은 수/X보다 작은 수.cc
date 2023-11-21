#include<iostream>
#include<vector>
#include<string>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int main() {

	fastio;

	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;

		if (a < X) cout << a << " ";
	}

	return EXIT_SUCCESS;
}