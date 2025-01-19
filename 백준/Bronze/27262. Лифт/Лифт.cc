#include <iostream>
using namespace std;

int N, K, A, B;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K >> A >> B;
	cout << (N + K - 2) * B << " " << (N - 1) * A;
}