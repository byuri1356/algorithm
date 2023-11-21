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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        if (i % 6 == 0 || i == n) cout << "Go! ";
    }
}