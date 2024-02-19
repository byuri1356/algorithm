#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int n, arr1[402], arr2[402], len1, len2, dp[402][402][402];

int sol(int a, int b, int l) {
	int& ref = dp[a][b][l];
	if (ref != -1e9) return ref;

	if (l == n) return 0;

	if (len1 - a + l < n) ref = max(ref, sol(a, b + 1, l + 1));
	if (len2 - b + l < n) ref = max(ref, sol(a + 1, b, l + 1));

	return ref = max(ref, arr1[a] * arr2[b] + sol(a + 1, b + 1, l + 1));
}

int main() {

	fastio;

	fill(&dp[0][0][0], &dp[401][401][402], -1e9);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr1[len1];
		if (arr1[len1]) len1++;
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr2[len2];
		if (arr2[len2]) len2++;
	}

	cout<<sol(0, 0, 0);

	//cout << "!";

}