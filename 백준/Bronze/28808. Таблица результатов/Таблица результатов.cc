#include<iostream>
using namespace std;

int main(){
    int n, m, ans=0; cin>>n>>m;
    char c[100][100];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>c[i][j];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(c[i][j] == '+'){
               ans++;
               break;
            }
        }
    }
    cout<<ans;
}