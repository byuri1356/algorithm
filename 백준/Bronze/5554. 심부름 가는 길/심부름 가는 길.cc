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

    int tmp, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum / 60 << "\n";
    cout << sum % 60 << "\n";
}