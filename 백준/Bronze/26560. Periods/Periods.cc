#include <iostream>
#include <string>
using namespace std;

void solve(void) {
  string s; getline(cin, s);

  cout << s << (s.back() != '.' ? "." : "") << "\n";
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  while (n--) solve();
  return 0;
}