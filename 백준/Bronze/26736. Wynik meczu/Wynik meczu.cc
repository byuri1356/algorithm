#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str; cin >> str;

  int cntA = count(str.begin(), str.end(), 'A'),
      cntB = count(str.begin(), str.end(), 'B');

  cout << cntA << " : " << cntB << "\n";

  return 0;
}