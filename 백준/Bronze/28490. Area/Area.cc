#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;

  int mx = 0;
  for (int i = 0; i < n; i++) {
    int h, w; cin >> h >> w;
    mx = max(mx, h * w);
  }

  cout << mx << "\n";

  return 0;
}