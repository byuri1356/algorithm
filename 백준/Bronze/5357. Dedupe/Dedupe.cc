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

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        string ans = input.substr(0, 1);

        for (size_t j = 1; j < input.length(); j++) {
            if (input[j] == input[j - 1]) continue;
            ans += input[j];
        }

        cout << ans << "\n";
    }
}