#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  for (int t = 0; t < n; t++) {
    string input;
    int i, j;
    cin >> input >> i >> j;

    string ret = input.substr(0, i) + input.substr(j);
    cout << ret << "\n";
  }

  return 0;
}