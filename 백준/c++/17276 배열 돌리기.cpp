#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 n, d, arr[500][500], arr1[500][500];
vector<int64> v;



int main() {
    fastio;

    int64 T;
    cin >> T;
    for (int64 t = 0; t < T; ++t) {
        cin >> n >> d;
        d = ((d + 360) / 45) % 8;

        for (int64 i = 0; i < n; ++i) {
            for (int64 j = 0; j < n; ++j) {
                cin >> arr[i][j];
                arr1[i][j] = arr[i][j];
            }
        }

        vector<int64> v[4];
        for (int64 i = 0; i < n; ++i) {
            v[0].push_back(arr[i][i]);
            v[1].push_back(arr[i][n / 2]);
            v[2].push_back(arr[i][n - 1 - i]);
            v[3].push_back(arr[n / 2][n - 1 - i]);
        }
        
        if (d == 0) {

        }
        else if (d == 1) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[3][n -1 -i];
                arr1[i][n / 2] = v[0][i];
                arr1[i][n - 1 - i] = v[1][i];
                arr1[n / 2][n - 1 - i] = v[2][i];
            }
        }
        else if (d == 2) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[2][n - 1 - i];
                arr1[i][n / 2] = v[3][n - 1 - i];
                arr1[i][n - 1 - i] = v[0][i];
                arr1[n / 2][n - 1 - i] = v[1][i];
            }
        }
        else if (d == 3) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[1][n - 1 - i];
                arr1[i][n / 2] = v[2][n - 1 - i];
                arr1[i][n - 1 - i] = v[3][n - 1 - i];
                arr1[n / 2][n - 1 - i] = v[0][i];
            }
        }
        else if (d == 4) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[0][n - 1 - i];
                arr1[i][n / 2] = v[1][n - 1 - i];
                arr1[i][n - 1 - i] = v[2][n - 1 - i];
                arr1[n / 2][n - 1 - i] = v[3][n - 1 - i];
            }
        }
        else if (d == 5) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[3][i];
                arr1[i][n / 2] = v[0][n - 1 - i];
                arr1[i][n - 1 - i] = v[1][n - 1 - i];
                arr1[n / 2][n - 1 - i] = v[2][n - 1 - i];
            }
        }
        else if (d == 6) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[2][i];
                arr1[i][n / 2] = v[3][i];
                arr1[i][n - 1 - i] = v[0][n - 1 - i];
                arr1[n / 2][n - 1 - i] = v[1][n - 1 - i];
            }
        }
        else if (d == 7) {
            for (int64 i = 0; i < n; ++i) {
                arr1[i][i] = v[1][i];
                arr1[i][n / 2] = v[2][i];
                arr1[i][n - 1 - i] = v[3][i];
                arr1[n / 2][n - 1 - i] = v[0][n - 1 - i];
            }
        }

        for (int64 i = 0; i < n; ++i) {
            for (int64 j = 0; j < n; ++j) {
                cout << arr1[i][j] << ' ';
            }
            cout << "\n";
        }

    }

    return EXIT_SUCCESS;
}