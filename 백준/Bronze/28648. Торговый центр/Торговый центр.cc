#include<iostream>
using namespace std;

int main(){
    
    int n, a, b, ans = 2000000000; cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a>>b;
        if(a+b < ans) ans = a+b;
    }
    
    cout<<ans;
    
}