#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int dp[3000001];
vector<int> arr;
bool isNotDecimal[3000001];

int main() {

	fastio;

	int a, b;

	while (1) {

		cin >> a >> b;
		if (a == 0 && b == 0) break;

		cout << a + b << "\n";

	}

}