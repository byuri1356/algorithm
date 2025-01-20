#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;

  int a1 = a * b, a2 = c * d;

  if (a1 > a2) cout << "M\n";
  else if (a1 < a2) cout << "P\n";
  else cout << "E\n";

  return 0;
}