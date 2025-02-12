#include<iostream>
using namespace std;

int main(){
    int a,b,c,d; cin>>a>>b>>c;
    d = b <= c ? c-b : a - b + c;
    cout<<d;
}