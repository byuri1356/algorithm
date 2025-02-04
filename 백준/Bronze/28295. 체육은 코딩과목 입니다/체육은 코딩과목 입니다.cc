#include<iostream>
using namespace std;

int main(){
    
    int n, d=0;
    for(int i=0; i<10; ++i){
        cin>>n;
        if(n == 1) d +=1;
        else if(n == 2) d+=2;
        else d +=3;
        d %=4;
    }
    if(d==0) cout<<"N";
    else if(d==1) cout<<"E";
    else if(d==2) cout<<"S";
    else cout<<"W";
}