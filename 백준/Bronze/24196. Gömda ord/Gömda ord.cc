#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string encrt; cin >> encrt;

  string ans = "";
  int idx = 0;
  while (true) {
    if ((size_t)idx == encrt.size() - 1) break ;

    ans += encrt[idx];
    idx += encrt[idx] - 'A' + 1;
  }

  ans += encrt[encrt.size() - 1];
  cout << ans << "\n";

  return 0;
}