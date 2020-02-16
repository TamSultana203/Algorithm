#include<bits/stdc++.h>
using namespace std;

void ssumof (){
    
    int sum=0;
    for(int i=0; i<1000; i++){
        sum+=i;
    }
    
}


int main(){
    int n, x=1;
    int ar[21];
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    sort(ar, ar+n);
    for(int i=0; i<n && ar[i]<=x; i++)
        x+=ar[i];
    
    cout <<x<< endl; 
    return 0;
}
