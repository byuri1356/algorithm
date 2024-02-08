#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int n, w[10001], dp[10001][2];
vector<int> adj[10001], track;

void tracking(int cur, int pnt, int stat) {

	if (stat) track.push_back(cur);

	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];

		if (next == pnt) continue;
		
		if (stat) tracking(next, cur, 0);
		else if (dp[next][0] < dp[next][1])tracking(next, cur, 1);
		else tracking(next, cur, 0);
	}
}


int sol(int cur, int pnt, int stat) {

	int& ref = dp[cur][stat];

	if (ref != -1) return ref;

	ref = stat ? w[cur] : 0;

	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];

		if (next == pnt) continue;

		ref += stat ? sol(next, cur, 0) : max(sol(next, cur, 0), sol(next, cur, 1));
	}

	return ref;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << max(sol(1, 1, 0), sol(1, 1, 1))<<"\n";

	if (dp[1][0] < dp[1][1]) tracking(1, 1, 1);
	else tracking(1, 1, 0);

	sort(track.begin(), track.end());
	track.erase(unique(track.begin(), track.end()), track.end());

	for (auto& it : track) cout << it << " ";

	//cout << "!";
}