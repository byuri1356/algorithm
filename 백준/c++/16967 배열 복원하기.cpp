#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 B[600][600];

int main() {
    fastio;

    int64 H, W, X, Y;
    cin >> H >> W >> X >> Y;

    for (int64 i = 0; i < H + X; ++i) {
        for (int64 j = 0; j < W + Y; ++j) {
            cin >> B[i][j];
        }
    }

    for (int64 i = X; i < H; ++i) {
        for (int64 j = Y; j < W; ++j) {
            B[i][j] -= B[i - X][j - Y];
        }
    }

    for (int64 i = 0; i < H; ++i) {
        for (int64 j = 0; j < W ; ++j) {
            cout << B[i][j] << ' ';
        }
        cout << "\n";
    }

    return EXIT_SUCCESS;
}