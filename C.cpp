#include <bits/stdc++.h>
using namespace std; 

long long int numberOfPaths(int m, int n) 
{ 
    
    long long int count[m][n]; 
    for (long long int i = 0; i < m; i++) 
        for (long long int j = 0; j < n; j++) 
            count[i][j] = 1; 

    for (long long int i = 1; i < m; i++) { 
        for (long long int j = 1; j < n; j++) 
            count[i][j] = (count[i - 1][j] + count[i][j - 1]+ count[i-1][j-1])%1711276033; 
    } 
    return count[m - 1][n - 1]; 
} 


int main() 
{ 
    long long int n, m;
    cin>>n>>m;
    cout << numberOfPaths(n, m)<<endl; 
    return 0; 
} 
