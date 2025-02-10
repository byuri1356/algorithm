#include<iostream>
using namespace std;

int main(){
    
    int a, b, mn; cin>>a>>b;
    mn = a < b ? a : b;
    mn = a == b ? 2 * mn : 2 * mn + 1;
    cout<<mn;
}