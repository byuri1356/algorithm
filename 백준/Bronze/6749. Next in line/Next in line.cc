#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;


int main() {

	fastio;

    int a, b, differ;
    cin >> a >> b;
    differ = b - a;
    cout << b + differ;
    return 0;

}