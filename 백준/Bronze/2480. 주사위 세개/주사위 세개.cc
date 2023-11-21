#include<iostream>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + a * 1000;
    }
    else if (a == b || a == c) {
        cout << 1000 + a * 100;
    }
    else if (b == c) {
        cout << 1000 + b * 100;
    }
    else {
        cout << max({ a,b,c }) * 100;
    }
    return 0;


}