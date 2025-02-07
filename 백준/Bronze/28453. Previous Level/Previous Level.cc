#include<iostream>
using namespace std;

int main(){
    
    int n; cin>>n;
    while(n--){
        int m; cin>>m;
        if(m == 300) cout<<"1 ";
        else if(m >= 275) cout<<"2 ";
        else if(m >= 250) cout<<"3 ";
        else cout<<"4 ";
    }
}