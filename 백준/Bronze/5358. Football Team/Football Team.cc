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
    while (1) {
        getline(cin, s);
        if (cin.eof()) break;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'e') cout << 'i';
            else if (s[i] == 'i') cout << 'e';
            else if (s[i] == 'E') cout << 'I';
            else if (s[i] == 'I') cout << 'E';
            else cout << s[i];
        }
        cout << "\n";
    }
}