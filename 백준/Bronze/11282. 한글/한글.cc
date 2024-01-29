#include <iostream>
#include <string>
using namespace std;

int main(void){
	int N;
	string S;
	cin>>N;
	N+=3071;
	S.push_back(N/4096+234);
	S.push_back(N/64%64+128);
	S.push_back(N%64+128);
	cout<<S;
	return 0;
}