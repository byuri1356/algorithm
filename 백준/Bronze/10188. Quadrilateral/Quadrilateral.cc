#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cntCase; cin >> cntCase;

  for (int i = 0; i < cntCase; i++) {
    int len, width; cin >> len >> width;

    for (int j = 0; j < width; j++) {
      for (int k = 0; k < len; k++)
        cout << "X";
      cout << "\n";
    }

    if (i < cntCase - 1) cout << "\n";
  }

  return 0;
}