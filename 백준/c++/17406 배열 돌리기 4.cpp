#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 N, M, K, arr0[51][51], arr1[51][51], vit[6], ans = INF;
vector<tuple<int64, int64, int64>> v;

inline void checkArr(int64 r, int64 c, int64 s) {
    
    for (int64 i = 1; i <= s; ++i) {
        for (int64 j = c - i + 1; j <= c + i; ++j) {
            arr1[r - i][j] = arr0[r - i][j - 1];
        }
        for (int64 j = r - i + 1; j <= r + i; ++j) {
            arr1[j][c + i] = arr0[j - 1][c + i];
        }
        for (int64 j = c - i; j < c + i; ++j) {
            arr1[r + i][j] = arr0[r + i][j + 1];
        }
        for (int64 j = r - i; j < r + i; ++j) {
            arr1[j][c - i] = arr0[j + 1][c - i];
        }
    }

}

inline void Rot(int64 dep) {
    int64 arr[51][51];
    for (int64 i = 1; i <= N; ++i) { 
        for (int64 j = 1; j <= M; ++j) {
            arr[i][j] = arr1[i][j];
        }
    }

    if (dep == K) {
        for (int64 i = 1; i <= N; ++i) {
            int64 sum = 0;
            for (int64 j = 1; j <= M; ++j) {
                sum += arr[i][j];
            }
            ans = min(ans, sum);
        }
        for (int64 i = 1; i <= N; ++i) {
            for (int64 j = 1; j <= M; ++j) {
                arr[i][j] = 1;
            }
        }
        return; 
    }

    for (int64 i = 0; i < v.size(); ++i) {
        if (!vit[i]) {
            vit[i] = true;
            for (int64 j = 1; j <= N; ++j) {
                for (int64 k = 1; k <= M; ++k) {
                    arr0[j][k] = arr[j][k];
                    arr1[j][k] = arr[j][k];
                }
            }
            checkArr(get<0>(v[i]), get<1>(v[i]), get<2>(v[i])); vit[i]; dep;
            Rot(dep + 1);
            vit[i] = false;
        }
    }

}

int main() {
    fastio;

    cin >> N >> M >> K;

    for (int64 i = 1; i <= N; ++i) {
        for (int64 j = 1; j <= M; ++j) {
            cin >> arr0[i][j];
            arr1[i][j] = arr0[i][j];
        }
    }
    
    for (int64 i = 0; i < K; ++i) {
        int64 r, c, s;
        cin >> r >> c >> s;
        v.push_back({ r, c, s });
    }

    Rot(0);
   
    cout << ans;

    return EXIT_SUCCESS;
}