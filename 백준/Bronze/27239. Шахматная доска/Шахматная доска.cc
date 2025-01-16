#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N; N--;
	cout << (char)('a' + (N % 8)) << N / 8 + 1;
}