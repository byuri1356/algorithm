#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int caseCnt; cin >> caseCnt;

  for (int i = 0; i < caseCnt; i++) {
    int group, initialCandies, evolveCandies;
    cin >> group >> initialCandies >> evolveCandies;

    int requiredCandies = evolveCandies - initialCandies;

    int requriedKm;
    if (group == 1) requriedKm = requiredCandies;
    else if (group == 2) requriedKm = 3 * requiredCandies;
    else requriedKm = 5 * requiredCandies;

    if (requriedKm <= 0) cout << "0\n";
    else  cout << requriedKm << "\n";
  }

  return 0;
}