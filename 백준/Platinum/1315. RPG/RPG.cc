#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int n, quest[51][3], dp[1001][1001];
bool visited[51];

int sol(int l, int r) {
	
	int& ref = dp[l][r];

	if (ref != -1) return ref;

	ref = 0;

	int point = 0;
	vector<int> checkPoint;

	for (int i = 0; i < n; ++i) {
		if (quest[i][0] <= l || quest[i][1] <= r) {
			ref++;
			if (visited[i]) continue;

			point += quest[i][2];
			visited[i] = true;
			checkPoint.push_back(i);
		}
	}

	for (int i = 0; i <= point; ++i) ref = max(ref, sol(min(1000, l + i), min(1000, r + point - i)));
	for (auto& it : checkPoint) visited[it] = false;

	return ref;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> quest[i][0] >> quest[i][1] >> quest[i][2];

	cout << sol(1, 1);

	//cout << "!";
}