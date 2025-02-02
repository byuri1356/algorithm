#include <iostream>
using namespace std;

int N, X;
int arr[100000];
int mn = 1000000007;

int main() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> arr[i];
	N--;
	for (int i = 0; i < N; i++) mn = min(mn, arr[i] + arr[i + 1]);

	cout << mn * X;
}