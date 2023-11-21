#include<iostream>
#include<vector>
#include<string>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int main() {

	fastio;

	int N;
	int64 ans = 1;
	cin >> N;
	if (!N) cout << "1";
	else {
		for (int i = 1; i <= N; ++i) {
			ans *= i;
		}
		cout << ans;
	}

	return EXIT_SUCCESS;
}