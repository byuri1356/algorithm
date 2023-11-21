#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 N, B;

class _map {
public: 
	int64 matrix[5][5] = {};
	_map(){}
	_map(int64 N) {
		int64 n;
		for (int64 i = 0; i < N;) {
			for (int64 j = 0; j < N;) {
				cin >> n;
				matrix[i][j] = n;
				++j;
			}
			++i;
		}
	}

	_map operator* (_map& m) {
		_map n;
		for (int64 i = 0; i < N;) {
			for (int64 j = 0; j < N;) {
				for (int64 k = 0; k < N;) {
					n.matrix[i][j] += ((this->matrix[i][k] % 1000) * (m.matrix[k][j] % 1000)) % 1000 ;
					n.matrix[i][j] %= 1000;
					++k;
				}
				++j;
			}
			++i;
		}
		return n;
	}

	inline void show() {
		for (int64 i = 0; i < N;) {
			for (int64 j = 0; j < N;) {
				cout << matrix[i][j] % 1000 << ' ';
				++j;
			}
			cout << "\n";
			++i;
		}
	}
};

inline _map Solve(_map &m, int64 b) {
	if (b == 1)
		return m;
	else if (b % 2) {
		return Solve(m, b - 1) * m;
	}
	_map half = Solve(m, b / 2);
	
	return half * half;
}

int main() {
	fastio;
	
	cin >> N >> B;

	_map m(N);
	_map n = Solve(m, B);
	n.show();

	return EXIT_SUCCESS;
}