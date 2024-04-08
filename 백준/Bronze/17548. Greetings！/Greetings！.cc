#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string greeting; cin >> greeting;

  int cntE = 0;
  for (char c : greeting)
    if (c == 'e') cntE++;

  cout << "h";
  for (int i = 0; i < 2 * cntE; i++)
    cout << "e";
  cout << "y\n";

  return 0;
}