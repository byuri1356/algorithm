#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

typedef struct node {
    char n;
    int64 left = -1, right = -1;
}node;

vector<node> vn;

inline void postOrder(int64 cur) {
    if (cur == -1) return;

    postOrder(vn[cur].left);
    postOrder(vn[cur].right);
    cout << vn[cur].n;
}

inline void inOrder(int64 cur) {
    if (cur == -1) return;

    inOrder(vn[cur].left);
    cout << vn[cur].n;
    inOrder(vn[cur].right);
}

inline void preOrder(int64 cur) {
    if (cur == -1) return;
    
    cout << vn[cur].n;
    preOrder(vn[cur].left);
    preOrder(vn[cur].right);
}

int main() {
    fastio;

    char a, b, c, d = 'A';
    int64 N, A, B, C;
    cin >> N;
    for (int64 i = 0; i < N; ++i) {
        vn.push_back({d++});
    }

    for (int64 i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        if (a == '.') A = -1;
        else A = (int)a - 65;
        if (b == '.') B = -1;
        else B = (int)b - 65;
        if (c == '.') C = -1;
        else C = (int)c - 65;
        
        vn[A].left = B;
        vn[A].right = C;
    }

    preOrder(0); cout << "\n";
    inOrder(0); cout << "\n";
    postOrder(0); cout << "\n";

    return EXIT_SUCCESS;
}