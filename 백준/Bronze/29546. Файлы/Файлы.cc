#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> v(n), vv;
    for(int i=0; i<n; ++i) cin>>v[i];
    
    int k; cin>>k;
    for(int i=0; i<k; ++i){
        int a,b; cin>>a>>b;
        for(int j=a-1; j<b; ++j) vv.push_back(v[j]);
    }
    
    for(auto& a : vv){
        cout<<a<<"\n";
    }
}