#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int a, b, diff;

int main() {

	fastio;

    int a[4];

    for (int i = 0; i < 4; i++) cin >> a[i];
    if (a[0] > a[1] && a[1] > a[2] && a[2] > a[3]) cout << "Fish Diving";
    else if (a[0] < a[1] && a[1] < a[2] && a[2] < a[3]) cout << "Fish Rising";
    else if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) cout << "Fish At Constant Depth";
    else cout << "No Fish";

}