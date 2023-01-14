#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool arr[50][50];
vector<pair<int64, int64>> v;

int main() {
    fastio;

    int64 N, M;
    cin >> N >> M;

    v.push_back({ 0,1 });
    for (int64 i = 2; i <= M; ++i) {
        v.push_back({ 1, i });
    }

    for (int64 i = M; i < N - 1; ++i) {
        v.push_back({ i, i + 1 });
    }

    for (auto iter : v) {
        cout << iter.first << ' ' << iter.second;
        cout << "\n";
    }

    return EXIT_SUCCESS;
}