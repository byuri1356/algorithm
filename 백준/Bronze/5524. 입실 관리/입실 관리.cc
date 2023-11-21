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

    string s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {   
                s[i] = tolower(s[i]);
            }
        }
        cout << s << "\n";
    }
}