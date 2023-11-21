#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;



int main() {

	fastio;

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;

		cout << "Case #" << i << ": " << a + b << "\n";
	}

	return EXIT_SUCCESS;
}