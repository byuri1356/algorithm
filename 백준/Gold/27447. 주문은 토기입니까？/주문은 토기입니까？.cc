#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int N, M, lastclient;
int coffeeShop[4][1000001]; // 토기, 만들 커피, 만들어진 커피, 손님
bool tk = true;

int main() {
	fastio;

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (a - M < 0) {
			coffeeShop[1][0]++;
		}
		else {
			coffeeShop[1][a - M]++;
		}

		coffeeShop[3][a]++;
		if (i == N - 1) lastclient = a;
	}
	coffeeShop[0][0] = 1;
	if (coffeeShop[3][0]) tk = false;
	else {
		for (int i = 1; i <= lastclient; ++i) {
			coffeeShop[0][i] = coffeeShop[0][i - 1], coffeeShop[1][i] += coffeeShop[1][i - 1], coffeeShop[2][i] += coffeeShop[2][i - 1];
			if (coffeeShop[3][i]) {
				if (coffeeShop[2][i] < 1) {
					tk = false;
					break;
				}
				else coffeeShop[2 ][i]--;
			}
			else if (coffeeShop[1][i]) {
				if (coffeeShop[0][i]) {
					coffeeShop[0][i]--;
					coffeeShop[1][i]--;
					coffeeShop[2][i]++;
				}
				else {
					coffeeShop[0][i]++;
				}
			}
			else {
				coffeeShop[0][i]++;
			}
		}
	}

	if (tk) cout << "success";
	else cout << "fail";

	return EXIT_SUCCESS;
}