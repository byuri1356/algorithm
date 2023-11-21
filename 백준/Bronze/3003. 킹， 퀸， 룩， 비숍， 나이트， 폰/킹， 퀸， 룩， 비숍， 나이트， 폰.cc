#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[6] = { 1, 1, 2, 2, 2, 8 };

int main() {
    fastio;
    
    int64 a;

    for (int64 i = 0; i < 6; ++i) {
        cin >> a;
        cout << arr[i] - a << ' ';
    }

    return EXIT_SUCCESS;
}