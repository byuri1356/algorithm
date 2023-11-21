#include <iostream>
#include <vector>
using namespace std;
using int64 = int64_t;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 A, B, C, D;
	cin >> A >> B >> C;

	D = A ^ B;
	if (C % 2 == 0) cout << A;
	else cout << D;

	return EXIT_SUCCESS;
}