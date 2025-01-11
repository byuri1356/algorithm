#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string str; cin >> str;

  map<char, char> m = {
    {'a', '4'},
    {'e', '3'},
    {'i', '1'},
    {'o', '0'},
    {'s', '5'}
  };

  for (char& c : str) {
    if (m.find(c) != m.end())
      c = m[c];
  }

  cout << str << "\n";

  return 0;
}