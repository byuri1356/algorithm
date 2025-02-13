#include<iostream>
using namespace std;

int main(){
    
    int n, arr[1000], ans = 0;
    cin>>n;
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=0; i<n; ++i){
        int a,b; cin>>a>>b;
        if(arr[i]) ans = a < b ? ans + b - a : ans; 
    }
    
    cout<<ans;
}