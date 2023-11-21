#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using int64 = int64_t;

int arr[52][52][52];
bool _arr[52][52][52];
inline int w(int a, int b, int c) {
	if ((a <= 0) || (b <= 0) || (c <= 0)) {
		return 1;
	}
	else if (_arr[a][b][c])
		return arr[a][b][c];
	else if ((a > 20) || (b > 20) || (c > 20)) {
		arr[a][b][c] = w(20, 20, 20);
		_arr[a][b][c] = true;
		return arr[a][b][c];
	}
	else if ((a < b) && (b < c)) {
		arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		_arr[a][b][c] = true;
		return arr[a][b][c];
	}
	else {
		arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		_arr[a][b][c] = true;
		return arr[a][b][c];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c, ans;
	for (;;) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		else {
			ans = w(a, b, c);
			cout << "w(" << a << ", " << b << ", " << c << ") = " << ans <<"\n";
		}
	
	}
	

	return EXIT_SUCCESS;
}