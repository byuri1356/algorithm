#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 N, M, R, arr1[100][100], arr2[100][100];

inline void display_arr1() {
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cout << arr1[i][j] << ' ';
		}
		cout << "\n";
	}
}

inline void rotate_arr1() {
	int64 holder;

	for (int64 i = 0; i < M; ++i) {
		for (int64 j = 0; j < N / 2; ++j) {
			holder = arr1[j][i];
			arr1[j][i] = arr1[N - 1 - j][i];
			arr1[N - 1 - j][i] = holder;
		}
	}
}

inline void rotate_arr2() {
	int64 holder;

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M / 2; ++j) {
			holder = arr1[i][j];
			arr1[i][j] = arr1[i][M - 1 - j];
			arr1[i][M - 1 - j] = holder;
		}
	}
}

inline void rotate_arr3() {
	int64 arr2[100][100], holder = N;
	
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr2[j][N-1-i] = arr1[i][j];
		}
	}

	N = M; M = holder;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

inline void rotate_arr4() {
	int64 arr2[100][100], holder = N;

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr2[M-1-j][i] = arr1[i][j];
		}
	}

	N = M; M = holder;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

inline void rotate_arr5() {
	int64 arr2[100][100], half_N = N / 2, half_M = M / 2;

	for (int64 i = 0; i < half_N; ++i) {
		for (int64 j = 0; j < half_M; ++j) {
			arr2[i][half_M + j] = arr1[i][j];
		}
	}
	for (int64 i = 0; i < half_N; ++i) {
		for (int64 j = half_M; j < M; ++j) {
			arr2[half_N + i][j] = arr1[i][j];
		}
	}

	for (int64 i = half_N; i < N; ++i) {
		for (int64 j = half_M; j < M; ++j) {
			arr2[i][j - half_M] = arr1[i][j];
		}
	}

	for (int64 i = half_N; i < N; ++i) {
		for (int64 j = 0; j < half_M; ++j) {
			arr2[i - half_N][j] = arr1[i][j];
		}
	}

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}

}

inline void rotate_arr6() {
	int64 arr2[100][100], half_N = N / 2, half_M = M / 2;

	for (int64 i = 0; i < half_N; ++i) {
		for (int64 j = 0; j < half_M; ++j) {
			arr2[half_N + i][j] = arr1[i][j];
		}
	}
	for (int64 i = 0; i < half_N; ++i) {
		for (int64 j = half_M; j < M; ++j) {
			arr2[i][j - half_M] = arr1[i][j];
		}
	}

	for (int64 i = half_N; i < N; ++i) {
		for (int64 j = half_M; j < M; ++j) {
			arr2[i - half_N][j] = arr1[i][j];
		}
	}

	for (int64 i = half_N; i < N; ++i) {
		for (int64 j = 0; j < half_M; ++j) {
			arr2[i][j + half_M] = arr1[i][j];
		}
	}

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

int main() {
	fastio;

	int64 A;
	cin >> N >> M >> R;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cin >> arr1[i][j];
		}
	}

	for (int64 i = 0; i < R; ++i) {
		cin >> A;
		switch (A) {
		case 1:
			rotate_arr1();
			break;
		case 2:
			rotate_arr2();
			break;
		case 3:
			rotate_arr3();
			break;
		case 4:
			rotate_arr4();
			break;
		case 5:
			rotate_arr5();
			break;
		case 6:
			rotate_arr6();
			break;
		}
	}

	display_arr1();

	return EXIT_SUCCESS;
}