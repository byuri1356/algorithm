#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int rot[6][12] = {
	{36,37,38,18,19,20,45,46,47,27,28,29},
	{33,34,35,51,52,53,24,25,26,42,43,44},
	{6,7,8,44,41,38,11,10,9,45,48,51},
	{2,1,0,53,50,47,15,16,17,36,39,42},
	{0,3,6,35,32,29,9,12,15,18,21,24},
	{8,5,2,26,23,20,17,14,11,27,30,33}
};

int n, m, cube[54];
enum eop { U, D, F, B, L, R };
char op[256], color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

void rotate(int s, int d) {
	int q[12], q1[3][3];

	for (int i = 0; i < d; ++i) {
		copy(&cube[9 * s], &cube[9 * s] + 9, &q1[0][0]);

		for (int j = 0; j < 12; ++j) q[j] = cube[rot[s][j]];
		for (int j = 0; j < 12; ++j) cube[rot[s][j]] = q[(j + 3) % 12];
		for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) cube[9 * s + 3 * j + k] = q1[2 - k][j];
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	op['U'] = U;
	op['D'] = D;
	op['F'] = F;
	op['B'] = B;
	op['L'] = L;
	op['R'] = R;
	op['+'] = 1;
	op['-'] = 3;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		iota(cube, cube + 54, 0);

		cin >> m;
		for (int j = 0; j < m; ++j) {
			char a[2]; cin >> a[0] >> a[1];
			rotate(op[a[0]], op[a[1]]);
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << color[cube[3 * i + j] / 9];
			}
			cout << "\n";
		}
	}

	return 0;
}