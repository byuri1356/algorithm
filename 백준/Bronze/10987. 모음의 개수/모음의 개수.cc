#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	string st;
	cin >> st;

	int count = 0;
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
			count++;
		}
	}
	cout << count;

}