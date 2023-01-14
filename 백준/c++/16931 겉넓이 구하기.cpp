#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[102][102], ans, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
    fastio;

    int64 N, M;
    cin >> N >> M;
    
    for (int64 i = 1; i <= N; ++i) {
        for (int64 j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int64 i = 1; i <= N; ++i) {
        for (int64 j = 1; j <= M; ++j) {
            for (int64 k = 0; k < 4; ++k) {
                int64 next_x = i + dx[k];
                int64 next_y = j + dy[k];
                int64 sum = arr[i][j] - arr[next_x][next_y];
                if (sum > 0) ans += sum;
            }
        }
    }

    ans = ans + 2 * N * M;
    cout << ans;

    return EXIT_SUCCESS;
}