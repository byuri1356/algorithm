#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    string giftycon; cin >> giftycon;
    int dayLeft = stoi(giftycon.substr(2));
    if (dayLeft <= 90) ans++;
  }

  cout << ans << "\n";

  return 0;
}