#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int a = 0, b = 0, t;
    for (int i = 0; i < 4; i++) {
        cin >> t;
        a += t;
    }
    for (int i = 0; i < 4; i++) {
        cin >> t;
        b += t;
    }
    cout << max(a, b);


}