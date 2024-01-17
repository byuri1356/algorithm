#include<iostream>
#include<algorithm>
using namespace std;
 
int main() {
	string S; 
	cin >> S; 
	
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << count(S.begin(), S.end(), i) << ' ';
	}
	
	return 0;
}