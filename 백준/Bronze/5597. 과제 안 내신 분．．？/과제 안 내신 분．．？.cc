#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int arr[31];

int main() {
	fastio;


	for (int i = 0; i < 28; ++i) {
		int a;
		cin >> a;
		arr[a] = 1;
	}

	for (int i = 1; i < 31; ++i) {
		if (!arr[i]) cout << i << "\n";
	}

	return EXIT_SUCCESS;
}