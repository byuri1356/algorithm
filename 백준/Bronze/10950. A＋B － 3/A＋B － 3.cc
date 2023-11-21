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
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return EXIT_SUCCESS;
}