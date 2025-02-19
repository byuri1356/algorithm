#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c, aa, bb, cc; cin >> a >> b >> c >> aa >> bb >> cc;
    a *= aa, b *= bb, c *= cc;
    int mx = max({ a,b,c });
    vector<string> v;
    if (a == mx) v.push_back("Joffrey");
    if (b == mx) v.push_back("Robb");
    if (c == mx) v.push_back("Stannis");

    sort(v.begin(), v.end());

    for (auto& ans : v) {
        cout << ans << " ";
    }
}