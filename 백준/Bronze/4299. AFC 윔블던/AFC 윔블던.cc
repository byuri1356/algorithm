#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int a, b, x, y;
    cin >> a >> b;
    if (a < b)
        cout << "-1";
    else {
        x = (a + b) / 2;
        y = (a - b) / 2;
        if (x + y == a && x - y == b)
            cout << x << " " << y;
        else
            cout << "-1";
    }
}