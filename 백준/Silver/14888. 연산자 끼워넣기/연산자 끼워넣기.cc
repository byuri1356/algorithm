#include<iostream>
#include<algorithm>
using namespace std;

int r, c;
int visit[1502][1502];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool check[1502][1502];
char bd[1502][1502];

int n, arr[13], op[4], mx = -1e9, mi = 1e9;

void sol(int idx, int s) {
	if (idx == n) {
		mx = max(mx, s);
		mi = min(mi, s);
		return;
	}

	if (op[0] != 0) op[0]--, sol(idx + 1, s + arr[idx]), op[0]++;
	if (op[1] != 0) op[1]--, sol(idx + 1, s - arr[idx]), op[1]++;
	if (op[2] != 0) op[2]--, sol(idx + 1, s * arr[idx]), op[2]++;
	if (op[3] != 0) op[3]--, sol(idx + 1, s / arr[idx]), op[3]++;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cin >> op[0] >> op[1] >> op[2] >> op[3];

	sol(1, arr[0]);

	cout << mx << "\n" << mi;

	return 0;
}