#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool vit[1'000'001], sel[1'000'001];
int64 ans;
vector<int64> vertex[1'000'001];

inline void checkV(int64 cur) {

    for (auto iter : vertex[cur]) {
        if (!vit[iter]) {
            vit[iter] = true;
            checkV(iter);
         
            if (!sel[iter]) {
                if (!sel[cur]) {
                    sel[cur] = true;
                    ans++;
                }
               
            }
        }
    }
}

int main() {
    fastio;

    int64 N;
    cin >> N;
    for (int64 i = 0; i < N - 1; ++i) {
        int64 u, v;
        cin >> u >> v;

        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }

    vit[1] = true;
    checkV(1);

    cout << ans;

    return EXIT_SUCCESS;
}