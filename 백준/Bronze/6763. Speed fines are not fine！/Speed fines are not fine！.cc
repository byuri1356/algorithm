#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int a, b, diff;

int main() {

	fastio;

    cin >> a >> b;
    diff = a - b;
    if (diff >= 0)
        cout << "Congratulations, you are within the speed limit!";
    else {
        cout << "You are speeding and your fine is $";
        if (1 <= -diff && -diff <= 20) cout << 100;
        else if (21 <= -diff && -diff <= 30) cout << 270;
        else if (-diff >= 31) cout << 500;
        cout << ".";
    }

}