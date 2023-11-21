#include<iostream>
#include<string>
#include<map>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using vv = vector<vector<int64>>;

int h1, w1, h2, w2;
int PV[2] = { 5381, 5831 };
int MOD[2] = { (int)1e9 + 7, (int)1e9 + 9 };
int64 pivot, ans;

void columnHash(vv& table, vv& vec, int r, int h) {
	int64 up[2] = { vec[0][r], vec[0][r] }, down[2] = { 1, 1 };

	for (int i = 1; i < h1; ++i) {
		for (int j = 0; j < 2; ++j) {
			up[j] = (up[j] * PV[1] + vec[i][r]) % MOD[j];
			down[j] = down[j] * PV[1] % MOD[j];
		}
	}

	table[r].push_back((up[0] << 32 | up[1]) % MOD[0]);


	for (int i = h1; i < h; ++i) {
		for (int j = 0; j < 2; ++j) {
			up[j] = (up[j] - down[j] * vec[i - h1][r] % MOD[j] + MOD[j]) % MOD[j];
			up[j] = (up[j] * PV[1] + vec[i][r]) % MOD[j];
		}

		table[r].push_back((up[0] << 32 | up[1]) % MOD[0]);
	}

}

void rowHash(vv& vec, string& s, int r, int h) {
	int64 up[2] = { s[0], s[0] }, down[2] = { 1, 1 };

	for (int i = 1; i < w1; ++i) {
		for (int j = 0; j < 2; ++j) {
			up[j] = (up[j] * PV[0] + s[i]) % MOD[j];
			down[j] = down[j] * PV[0] % MOD[j];
		}
	}

	vec[h].push_back((up[0] << 32 | up[1]) % MOD[0]);

	for (int i = w1; i < r; ++i) {
		for (int j = 0; j < 2; ++j) {
			up[j] = (up[j] - down[j] * s[i - w1] % MOD[j] + MOD[j]) % MOD[j];
			up[j] = (up[j] * PV[0] + s[i]) % MOD[j];
		}

		vec[h].push_back((up[0] << 32 | up[1]) % MOD[0]);
	}

}

int main() {

	fastio;

	cin >> h1 >> w1 >> h2 >> w2;

	vv kvec(h1), tvec(h2);
	vv key(1), table(w2 - w1 + 1);

	for (int i = 0; i < h1; ++i) {
		string s;
		cin >> s;

		rowHash(kvec, s, w1, i);
	}

	columnHash(key, kvec, 0, h1);
	pivot = key[0][0];

	for (int i = 0; i < h2; ++i) {
		string s;
		cin >> s;

		rowHash(tvec, s, w2, i);
	}

	for (int i = 0; i < tvec[0].size(); ++i) {
		columnHash(table, tvec, i, h2);
	}


	for (int i = 0; i <= w2 - w1; ++i) {
		for (int j = 0; j <= h2 - h1; ++j) {
			if (pivot == table[i][j]) {
				ans++;
			}
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}