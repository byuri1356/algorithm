#include<iostream>
using namespace std;

int main(){
    string a,b; cin>>a>>b;
    for(int i=0; i<a.length(); ++i){
        if(a[i] < b[i]) cout<<b[i];
        else cout<<a[i];
    }
}