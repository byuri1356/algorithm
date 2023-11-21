#include<iostream>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 N, M, R, arr1[300][300];
int64 afew;

inline void rotate() {
	int64 arr2[300][300];
	int64 afew = min(N, M) / 2;
	for (int64 i = 0; i < afew; ++i) {
		int64 min_N = 0 + i;
		int64 max_N = N - 1 - i;
		int64 min_M = 0 + i;
		int64 max_M = M - 1 - i;
		int64 max_rotate = 2 * (max_N - min_N + 1) + 2 * (max_M - min_M + 1) - 4;
		int64 afew_rotate = R % max_rotate;


		for (int64 j = max_M; j >= min_M; --j) {
			int64 rotate_detail = ((afew_rotate + (max_M - j)) % max_rotate);

			if (rotate_detail <= max_M - min_M) {
				arr2[min_N][max_M - rotate_detail] = arr1[min_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[min_N + rotate_detail][min_M] = arr1[min_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[max_N][min_M + rotate_detail] = arr1[min_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[max_N - rotate_detail][max_M] = arr1[min_N][j];
				continue;
			}
		}

		for (int64 j = min_N; j < max_N; ++j) {
			int64 rotate_detail = ((afew_rotate + (j - min_N)) % max_rotate);

			if (rotate_detail <= max_N - min_N) {
				arr2[min_N + rotate_detail][min_M] = arr1[j][min_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[max_N][min_M + rotate_detail] = arr1[j][min_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[max_N - rotate_detail][max_M] = arr1[j][min_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[min_N][max_M - rotate_detail] = arr1[j][min_M];
				continue;
			}
		}

		for (int64 j = min_M; j <= max_M; ++j) {
			int64 rotate_detail = ((afew_rotate + (j - min_M)) % max_rotate);

			if (rotate_detail <= max_M - min_M) {
				arr2[max_N][min_M + rotate_detail] = arr1[max_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[max_N - rotate_detail][max_M] = arr1[max_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[min_N][max_M - rotate_detail] = arr1[max_N][j];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[min_N + rotate_detail][min_M] = arr1[max_N][j];
				continue;
			}
		}

		for (int64 j = max_N; j >= min_N; --j) {
			int64 rotate_detail = ((afew_rotate + (max_N - j)) % max_rotate);
			
			if (rotate_detail <= max_N - min_N) {
				arr2[max_N - rotate_detail][max_M] = arr1[j][max_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[min_N][max_M - rotate_detail] = arr1[j][max_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_M + min_M;
			}
			if (rotate_detail <= max_N - min_N) {
				arr2[min_N + rotate_detail][min_M] = arr1[j][max_M];
				continue;
			}
			else {
				rotate_detail = rotate_detail - max_N + min_N;
			}
			if (rotate_detail <= max_M - min_M) {
				arr2[max_N][min_M + rotate_detail] = arr1[j][max_M];
				continue;
			}
		}
	}
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cout << arr2[i][j] << ' ';
		}
		cout << "\n";
	}

}

int main() {
	fastio;

	cin >> N >> M >> R;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cin >> arr1[i][j];
		}
	}

	rotate();

	return EXIT_SUCCESS;
}