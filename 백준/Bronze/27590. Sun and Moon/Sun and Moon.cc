#include <iostream>
using namespace std;

int S, SS, M, MM;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> S >> SS >> M >> MM;
	S = SS - S, M = MM - M;

	while (S != M) {
		if (S < M) S += SS;
		else M += MM;
	}

	cout << S;
}