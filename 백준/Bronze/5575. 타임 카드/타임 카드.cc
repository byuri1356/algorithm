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

    int sh, sm, ss, eh, em, es;
    int start, end, t, h, m, s;
    for (int i = 0; i < 3; i++) {
        cin >> sh >> sm >> ss >> eh >> em >> es;
        start = (sh * 3600) + (sm * 60) + ss;
        end = (eh * 3600) + (em * 60) + es;
        t = end - start;
        h = t / 3600;
        m = (t % 3600) / 60;
        s = (t % 3600) % 60;

        cout << h << " " << m << " " << s << "\n";
    }


}