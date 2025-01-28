#include <iostream>
using namespace std;
bool a[26];
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'A'] = true;
    if (a['M' - 'A'] && a['O' - 'A'] && a['I' - 'A']
        && a['S' - 'A'] && a['B' - 'A']) cout << "YES";
    else cout << "NO";
    return 0;
}