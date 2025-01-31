#include<iostream>
using namespace std;

int main(){
    
    int a, b; cin>>a>>b;
    int t = a * 50 - b * 10;
    
    if(a>b) t +=500;
    cout<<t;
}