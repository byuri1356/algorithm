#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

class Fib {
public:
	int64 arr[2][2] = { {1,1},{1,0} };
	Fib() {}

	Fib operator* (Fib& m) {
		Fib tmp;
		for (int64 i = 0; i < 2; ) {
			for (int64 j = 0; j < 2; ) {
				tmp.arr[i][j] = 0;
				for (int64 k = 0; k < 2;) {
					tmp.arr[i][j] += ((this->arr[i][k] % 1'000'000'007 * m.arr[k][j] % 1'000'000'007)) % 1'000'000'007;
					tmp.arr[i][j] % 1'000'000'007;
					++k;
				}
				++j;
			}
			++i;
		}
		return tmp;
	}

	void show() {
		cout << arr[1][0] ;
	}

};

Fib split(Fib &m, int64 T) {
	if (T == 1) return m;
	else if (T % 2) return split(m, T-1) * m;
	
	Fib half = split(m, T / 2);
	
	return half * half;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	cin >> T;
	Fib f;
	
	if (T == 0) cout << 0;
	else {
		Fib result = split(f, T);
		Fib result_1 = result * f;
		cout << (result.arr[1][0] % 1'000'000'007 )* (result_1.arr[1][0] % 1'000'000'007) % 1'000'000'007;
	}

	return EXIT_SUCCESS;
}