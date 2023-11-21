#include<iostream>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a + (b + (c + d) / 60) / 60) % 24 << " " << (b + (c + d) / 60) % 60 << " " << (c + d) % 60;

}