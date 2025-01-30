#include <bits/stdc++.h>

using namespace std;

int main() {

  int t, p; cin >> t >> p;

  for (int i = 1; i < t; i++) {
    int pp; cin >> pp;
    p += pp;
  }

  cout << p << "\n";

  return 0;
}