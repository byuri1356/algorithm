#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int64 T, i, num, div, mod, ans=0;
	cin >> T;
	for (i = 8; i >= 0; ) {
		num = pow(10, i);
		if (T / num != 0) break;
		--i;
	}
	
	ans = (T - num+1)*(i+1);
	if (i > 0) {
		for (int64 j = i; j >= 1;) {
			ans += (pow(10, j) - pow(10, j - 1)) * j;
			--j;
		}
	}
	cout << ans;
	
	return EXIT_SUCCESS;
}