#include<iostream>
using namespace std;

int main(){
    int arr[100], T, t, Ans=0;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>arr[i];
    }
    cin>>t;
    for(int i=0; i<T; ++i){
        if(arr[i] == t) Ans++;
    }
    cout<<Ans;
    
    return EXIT_SUCCESS;
}